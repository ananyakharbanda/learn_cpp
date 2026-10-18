#include <cstddef>
#include <utility>
#include <iostream>

struct ControlBlock {
    size_t count;
};

template <typename T>
class SharedPtr {
    T* ptr_;
    ControlBlock* control_;

public:
    SharedPtr() noexcept {
        ptr_ = nullptr;
        control_ = nullptr; 
    }
    
    SharedPtr(std::nullptr_t) noexcept {
        ptr_ = nullptr;
        control_ = nullptr;
    }   

    explicit SharedPtr(T* ptr) {
        ptr_ = ptr;
        
        if (ptr_ == nullptr) {  
            control_ = nullptr;
        } else {
            control_ = new ControlBlock{1};
        }
    }

    SharedPtr(const SharedPtr& other) noexcept {
        ptr_ = other.ptr_;
        control_ = other.control_;
        if (control_) {
            control_->count++;
        }
    }
    
    SharedPtr(SharedPtr&& other) noexcept {
        ptr_ = other.ptr_;
        control_ = other.control_;
        other.ptr_ = nullptr;
        other.control_ = nullptr;
    }
    
    ~SharedPtr() {  
        if (control_ != nullptr) {
            control_->count -= 1;
            if (control_->count == 0) {
                delete ptr_;        
                delete control_;
            }
        }
    } 
    
    SharedPtr& operator=(const SharedPtr& other) noexcept {
        if (this != &other) {
            ptr_ = other.ptr_;
            control_ = other.control_;
        }
        return *this;
    }
    
    SharedPtr& operator=(SharedPtr&& other) noexcept {
        if (this != &other) {
            reset();

            ptr_ = other.ptr_;
            control_ = other.control_;  

            other.ptr_ = nullptr;
            other.control_ = nullptr;
        }
        return *this;
    }

    T& operator*() const noexcept {
        return *ptr_;
    }

    T* operator->() const noexcept {
        return ptr_;
    }
    
    T* get() const noexcept {
        return ptr_;
    }
    
    std::size_t use_count() const noexcept {
        if (control_) { 
            return control_->count;
        } else {
            return 0;
        }
    }
    
    bool unique() const noexcept {
        return (use_count() == 1);
    }
    
    explicit operator bool() const noexcept {
        return (ptr_ != nullptr);
    }
   
    void reset() noexcept {
        if (control_) { 
            control_->count -= 1;
            
            if (control_->count == 0) {
                delete ptr_;
                delete control_;    
            } else {
                ptr_ = nullptr;
                control_->count -= 1;
            }
        }
    }
    
    // void reset(T* ptr) {
    //    SharedPtr new_sp(ptr);
    // }
        
    void swap(SharedPtr& other) noexcept {
        std::swap(ptr_, other.ptr_);
        std::swap(control_, other.control_);
    }
};      

int main() {
    SharedPtr<int> p1;
    SharedPtr<int> p2(new int(10));
    SharedPtr<int> p3(nullptr);

    std::cout << *p2 << std::endl;
    std::cout << p1.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;

    SharedPtr<int> p4(p2);
    std::cout << p2.use_count() << std::endl;
    std::cout << p4.use_count() << std::endl;

    SharedPtr<int> p5(std::move(p4));
    std::cout << p5.use_count() << std::endl;
    std::cout << p4.use_count() << std::endl;

    SharedPtr<int> p6;
    p6 = p2;
    std::cout << p2.use_count() << std::endl;

    SharedPtr<int> p7;
    p7 = std::move(p6);
    std::cout << p7.use_count() << std::endl;

    std::cout << p2.get() << std::endl;
    std::cout << static_cast<bool>(p2) << std::endl;
    std::cout << static_cast<bool>(p1) << std::endl;

    p5.reset();
    std::cout << p2.use_count() << std::endl;
    std::cout << p5.use_count() << std::endl;

    // p7.reset(new int(20));
    // std::cout << *p7 << std::endl;
    // std::cout << p7.use_count() << std::endl;

    p2.swap(p7);
    std::cout << *p2 << std::endl;
    std::cout << *p7 << std::endl;

    return 0;
}

#include <utility>

template <typename T>

class UniquePtr {
private:
    T* ptr;

public:
    // 1. constructor
    explicit UniquePtr(T* p) {
        ptr = p;
    }
   
    // 2. destructor 
    ~UniquePtr() {
        delete ptr;
    }
   
    // 3. cannot copy 
    UniquePtr(const UniquePtr&) = delete;
    
    UniquePtr& operator=(const UniquePtr&) = delete;
    
    // 4. move constructor 
    UniquePtr(UniquePtr&& other) noexcept {
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    
    // 5. move assignment
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // 6. dereference
    T& operator *() const {
        return *ptr;
    }
    
    // 7. arrow operator
    T* operator->() const {
        return ptr;
    }
    
    // 8. Access raw pointer
    T* get() const {
        return ptr;
    }
    
    // 9. Check whether pointer exists
    explicit operator bool() const {
        return ptr != nullptr;
    }
    
    // 10. Give up ownership
    T* release() {
        return std::exchange(ptr, nullptr);
    }
    
    // 11. Replace owned object
    void reset(T* p = nullptr) {
        if (ptr != p) {
            delete ptr;
            ptr = p;
        }
    }
}; 

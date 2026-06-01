#include <iostream>
#include <utility>
#include <cassert>

struct ControlBlock {
    int ref_count;
    explicit ControlBlock(int refs = 1) : ref_count(refs) {}
};

template <typename T>

class SharedPtr {
private:
    T* ptr_;
    ControlBlock* ctrl_;
    
    void release() noexcept {
        if (!ctrl_)  return;
        
        --ctrl_->ref_count;
        log("release", ctrl_->ref_count);
        
        if (ctrl_->ref_count == 0) {
            delete ptr_;
            delete ctrl_;
        }
        
        ptr_ = nullptr;
        ctrl_ = nullptr;
    }
    
    static void log(const char* event, int count) {
        std::cout << " shared ptr " << event << " -> ref_count now " << count << std::endl;
    }
public:
    SharedPtr() noexcept : ptr_(nullptr), ctrl_(nullptr) {}
    
    explicit SharedPtr(T* raw) : ptr_(raw), ctrl_(raw ? new  ControlBlock(1) : nullptr) {}
    
    SharedPtr(const SharedPtr& other) noexcept 
        : ptr_(other.ptr_), ctrl_(other.ctrl_)
    {
        if (ctrl_) {
            ++ctrl_->ref_count;
            log("copy ctor", ctrl_->ref_count);
        }
    }
    
    SharedPtr(SharedPtr&& other) noexcept 
        : ptr_(std::exchange(other.ptr_, nullptr)),
        ctrl_(std::exchange(other.ctrl_, nullptr))
    {
        if (ctrl_) log("move ctor", ctrl_->ref_count);
    }
    
    SharedPtr& operator=(SharedPtr other) noexcept 
    {
        swap(other);
        return *this;
    }
    
    ~SharedPtr() {
        release();
    }

    T* get() const noexcept { return ptr_; }
    T& operator*() const noexcept { return *ptr_; }
    T* operator->() const noexcept { return ptr_; }
    int use_count() const noexcept { return ctrl_ ? ctrl_->ref_count : 0; } 
    explicit operator bool() const noexcept { return ptr_ != nullptr; }
    
    void reset(T* raw = nullptr) {
        SharedPtr tmp(raw);
        swap(tmp);
    }
    
    void swap(SharedPtr& other) noexcept {
        std::swap(ptr_, other.ptr_);
        std::swap(ctrl_, other.ctrl_);
    }
};

template <typename T, typename... Args>
SharedPtr<T> make_shared(Args&&... args) {
    return SharedPtr<T>(new T(std::forward<Args>(args)...));
}

struct Widget {
    int id;
    explicit Widget(int i) : id(i) {
        std::cout << "  Widget(" << id << ") constructed\n";
    }
    ~Widget() {
        std::cout << "  Widget(" << id << ") destroyed\n";
    }
};
 
int main() {
 
    std::cout << "\n--- make_shared creates one owner (ref=1) ---\n";
    SharedPtr<Widget> a = make_shared<Widget>(42);
    assert(a.use_count() == 1);
    std::cout << "  use_count = " << a.use_count() << "\n";
 
    std::cout << "\n--- copy: two owners share the same control block (ref=2) ---\n";
    SharedPtr<Widget> b = a;
    assert(a.use_count() == 2);
    assert(b.use_count() == 2);
    std::cout << "  use_count via a = " << a.use_count() << "\n";
    std::cout << "  use_count via b = " << b.use_count() << "\n";
    std::cout << "  same object? " << (a.get() == b.get() ? "yes" : "no") << "\n";
 
    std::cout << "\n--- move: ownership transfers, ref_count stays the same ---\n";
    SharedPtr<Widget> c = std::move(b);
    assert(!b);                 // b is now empty
    assert(c.use_count() == 2); // a and c share it
    std::cout << "  b is empty? " << (!b ? "yes" : "no") << "\n";
    std::cout << "  use_count via c = " << c.use_count() << "\n";
 
    {
        std::cout << "\n--- inner scope: third owner (ref=3) ---\n";
        SharedPtr<Widget> d = a;
        std::cout << "  use_count = " << d.use_count() << "\n";
 
        std::cout << "\n--- leaving inner scope: d destructs (ref→2) ---\n";
    }
    assert(a.use_count() == 2);
    std::cout << "  use_count back to " << a.use_count() << "\n";
 
    std::cout << "\n--- reset a: a releases (ref→1), only c remains ---\n";
    a.reset();
    assert(!a);
    assert(c.use_count() == 1);
    std::cout << "  c use_count = " << c.use_count() << "\n";
 
    std::cout << "\n--- c goes out of scope at end of main → Widget destroyed ---\n";
    return 0;  // c destructs here, ref→0, Widget deleted
}

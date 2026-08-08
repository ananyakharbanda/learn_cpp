#include <std::exchange>

template <typename T>

class UniquePtr {
private:
    T* ptr;

public:
    explicit UniquePtr(T* p) {
        ptr = P;
    }
    
    ~UniquePtr() {
        delete ptr;
    }
    
    UniquePtr(const UniquePtr&) = delete;
    
    UniquePtr& operator=(const UniquePtr&) = delete;
        
    UniquePtr(UniquePtr&& other) noexcept {
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
        }
        
        ptr = other.ptr;
        other.ptr = nullptr;
        
        return *this;
    }

    T& operator *() const
     
    

template <typename T>

class UniquePtr {
private:
    T* ptr;

public:
    UniquePtr() {
        ptr = nullptr;
    }
    
    explicit UniquePtr(T* p) {
        ptr = p;
    }
    
    ~UniquePtr() {
        delete ptr;
    }
        
    UniquePtr(const UniquePtr& other) = delete;
    
    UniquePtr& operator=(const UniquePtr& other) = delete;
    
    UniquePtr(UniquePtr&& other) noexcept {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }
    
    T* get() const {
        return ptr;
    }
    
    explicit operator bool() const {
        if (ptr == nullptr) {
            return false;
        }
        return true;
    }   
    
    T* release() {
        T* oldPtr = ptr;
        ptr = nullptr;
        return oldPtr;
    }

    void reset() {
        delete ptr;
        ptr = nullptr;
    }

    void reset(T* newPtr) {
        if (ptr != newPtr) {
            delete ptr;
            ptr = newPtr;
        }
    }
};

template <typename T>
class UniquePtr {
private:
    T* ptr;
    
public:
    UniquePtr() {
        ptr = nullptr;
    }
    
    explicit UniquePtr(T* newptr) {
        ptr = newptr;
    }
    
    ~UniquePtr() {
        delete ptr;
    }
    
    UniquePtr(const UniquePtr& incptr) = delete;
    
    UniquePtr& operator=(const UniquePtr& incptr) = delete;
    
    UniquePtr(UniquePtr&& other) {
        ptr = other.ptr;
        other = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other) {
        if (this != &other) {
            ptr = other.ptr;
            other = nullptr;
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
        if (ptr != nullptr) {
            return true;
        }   
        return false;
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
    
    void reset(T* newPointer) {
        if (ptr != newPointer) {
            delete ptr;
            ptr = newPointer;
        }
    }
}
    

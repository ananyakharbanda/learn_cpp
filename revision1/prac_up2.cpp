template <typename T>
class UP {

private:
    T* ptr;
    
public:
    // 1) default constructor
    UP() {
        ptr = nullptr;
    }

    // 2) constructor takes ownership
    explicit UP(T* incPtr) { 
        ptr = incPtr;
    }
    
    // 3) destructor
    ~UP() {
        delete ptr; 
    }

    // 4) no copy constructor
    UP(const UP& other) = delete;   

    // 5) no copy assignment
    UP& operator=(const UP&& other) = delete;
    
    // 6) move constructor
    UP(UP&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
    }
    
    // 7) move operator
    UP& operator=(const UP&& other) noexcept {
        if (this != &other) {
            delete ptr;     
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    
    // 8) dereference operator
    T& operator*() const {
        return *ptr;
    }
    
    // 9) arrow operator
    T& operator->() const {
        return ptr;
    }

    // 10) return raw ptr without giving up ownership
    T* get() const {
        return ptr;
    }
    
    // 11) check if we own something 
    explicit operator bool() const {
        if (ptr == nullptr) {
            return false;
        }

        return true;
    }
    
    // 12) give up ownership
    T* release() {
        T* oldPointer = ptr;
        ptr = nullptr;
        return oldPointer;
    }   
    
    // 13) delete curr obj and own nothing
    void reset() {
        delete ptr;
        ptr = nullptr;
    }
    
    // 14) delete curr obj and own a new one
    void reset(T* newPtr) {
        if (ptr != newPtr) {
            delete ptr;
            ptr = newPtr;
        }
    }
};

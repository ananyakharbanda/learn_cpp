template <typename T>
class UniquePtr {

private:
    T* ptr;

public:
    // 1. Default constructor
    UniquePtr() {

        ptr = nullptr;
    }

    // 2. Constructor that takes ownership
    explicit UniquePtr(T* incomingPointer) {

        ptr = incomingPointer;
    }

    // 3. Destructor
    ~UniquePtr() {

        delete ptr;
    }


    // 4. Copy constructor is forbidden
    UniquePtr(const UniquePtr& other) = delete;


    // 5. Copy assignment is forbidden
    UniquePtr& operator=(const UniquePtr& other) = delete;


    // 6. Move constructor
    UniquePtr(UniquePtr&& other) noexcept {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    // 7. Move assignment
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }

        return *this;
    }

    // 8. Dereference operator
    T& operator*() const {
        return *ptr;
    }

    // 9. Arrow operator
    T* operator->() const {
        return ptr;
    }

    // 10. Return raw pointer without giving up ownership
    T* get() const {
        return ptr;
    }

    // 11. Check whether we own something
    explicit operator bool() const {
        if (ptr == nullptr) {
            return false;
        }
        return true;
    }


    // 12. Give up ownership
    T* release() {
        T* oldPointer = ptr;
        ptr = nullptr;
        return oldPointer;
    }

    // 13. Delete current object and own nothing
    void reset() {
        delete ptr;
        ptr = nullptr;
    }

    // 14. Delete current object and own a new one
    void reset(T* newPointer) {
        if (ptr != newPointer) {
            delete ptr;
            ptr = newPointer;
        }
    }
};

#include <stdexcept>

template <typename T>
class Vector {
private:
    T* data;
    size_t size_;
    size_t capacity_;

public:
    Vector() {
        data = nullptr;
        size_ = 0;
        capacity_ = 0;
    }

    Vector(size_t n) {
        data = new T[n];
        // size_ = 0; (this is incorrect because all elements are value-initialized
        size_ = n;
        capacity_ = n;
    }
    
    Vector(size_t n, const T& value) {
        size_ = n;
        capacity_ = n;
        
        data = new T[capacity_];
    
        for (size_t i = 0; i < size_; i++) {
            data[i] = value;
        }
    }
    
    Vector(const Vector& other) { 
        data = new T[other.capacity_]; 
        size_ = other.size_;
        capacity_ = other.capacity_;
        for (size_t i = 0; i < size_; i++) {
            data[i] = other.data[i];
        }
    }
    
    Vector(Vector&& other) noexcept {
        data = other.data;
        size_ = other.size_;
        capacity = other.capacity_;
        
        other.data = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    
    ~Vector() {
        delete[] data; 
        data = nullptr;
    }
    
    Vector& operator=(const Vector& other) {
        if (this  == &other) {
            return *this;
        }
        delete[] data;
        data = new T[other.capacity_]; 
        size_ = other.size_;
        capacity_ = other.capacity_;
        for (size_t i = 0; i < size_; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }
    
    Vector& operator=(Vector&& other) noexcept {
        if (this == &other) {
            return *this;
        }
    
        delete[] data;
        data = other.data;
        size_ = other.size_;
        capacity = other.capacity_;
        
        other.data = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
        
        return *this;
    }
    
    size_t size() const {
        return size_;
    }
    
    size_t capacity() const {
        return capacity_;
    }
    
    bool empty() const {
        if (size_ != 0) {
            return false;
        } 
        return true;
    }
    
    T& operator[](size_t index) {
        return data[index];
    }
    
    const T& operator[](size_t index) const {
        return data[index]; 
    }
    
    T& at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("index out of range");
        } 
        return data[index];
    }
    
    const T& at(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("index out of range");
        }
        return data[index];          
    }
    
    T& front() {
        if (size_ != 0) {
            return data[0];
        }
        else {
            throw std::out_of_range("vector is empty");
        }
    }
     
    const T& front() const {
        if (size_ != 0) {
            return data[0];
        }
        else {
            throw std::out_of_range("vector is empty");
        }
    }
     
    T& back() { 
        if (size_ != 0) {
            return data[size_-1];
        }
        else {
            throw std::out_of_range("vector is empty");
        }
    } 
    
    const T& back() const { 
        if (size_ != 0) {
            return data[size_-1];
        }
        else {
            throw std::out_of_range("vector is empty");
        }
    } 
    
    void push_back(const T& value) {
        if (size_ < capacity_) {
            data[size_] = value;
            size_ += 1;
        } else {
            int new_capacity;
            if (capacity_ == 0) {
                new_capacity = 1;
            } else {
                capacity_ = new_capacity * 2;
            }
                
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size_; i++) {
                new_data[i] = data[i];
            }
            
            delete[] data;
                
            data = new_data;
            capacity_ = capacity_ * 2;
            data[size_] = value;
            size_ += 1;
        }
    }
    
    void pop_back() {
        if (size_ > 0) {
            size_ -= 1;
        }
    }
    
    void clear() {
        size_ = 0;
    }
};


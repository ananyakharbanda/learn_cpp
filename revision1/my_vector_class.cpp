#include <stdexcept>

template <typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    Vector() {
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    Vector(size_t n) {
        data = new T[n];
        size = 0;
        capacity = n;
    }
    
    Vector(size_t n, const T& value) {
        size = n;
        capacity = n;
        
        data = new T[capacity];
    
        for (size_t i = 0; i < n; i++) {
            data[i] = value;
        }
    }
    
    Vector(const Vector& other) { 
        data = new T[other.capacity]; 
        size = other.size;
        capacity = other.capacity;
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
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
        data = new T[other.capacity]; 
        size = other.size;
        capacity = other.capacity;
        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }
    
    size_t size() const {
        return size;
    }
    
    size_t capacity() const {
        return capacity;
    }
    
    bool empty() const {
        if (size != 0) {
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
        if (index >= size) {
            throw std::out_of_range("index out of range");
        } 
        return data[index];
    }
    
    const T& at(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("index out of range");
        }
        return data[index];          
    }
    
    T& front() {
        if (size != 0) {
            return data[0];
        }
        else {
            throw std::out_of_range("vector is empty");
        }
    }
     
    const T& front() const {
        if (size != 0) {
            return data[0];
        }
        else {
            throw std::out_of_range("vector is empty");
        }
    }
     
    T& back() { 
        if (size != 0) {
            return data[size-1];
        }
        else {
            throw std::out_of_range("vector is empty");
        }
    } 
    
    const T& back() const { 
        if (size != 0) {
            return data[size-1];
        }
        else {
            throw std::out_of_range("vector is empty");
        }
    } 
    
    void push_back(const T& value) {
        if (size < capacity) {
            data[size] = value;
            size += 1;
        } else {
            int new_capacity;
            if (capacity == 0) {
                new_capacity = 1;
            } else {
                new_capacity = capacity * 2;
            }
                
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            
            delete data[];
                
            data = new_data;
            capacity = capacity * 2;
            data[size] = value;
            size += 1;
        }
    }
    
    void pop_back() {
        if (size > 0) {
            size -= 1;
        }
    }
    
    void clear() {
        size = 0;
    }
        
};


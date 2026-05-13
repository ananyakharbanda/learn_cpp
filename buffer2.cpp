#include <iostream>
#include <algorithm>

class Buffer {
    int* data;
    size_t size;
   
    // friend is not a member of class, but can access your private data members
    friend void swap(Buffer& a, Buffer& b) noexcept {
        std::swap(a.data, b.data);
        std::swap(a.size, b.size);
    }
    
public:
    Buffer(size_t n) : data{new int[n]}, size{n} {}
    
    Buffer(const Buffer& other) {
        std::cout << "copy constructor called" << std::endl;
        this->size = other.size;
        this->data = new int[other.size]; // give the this->data memory
        std::copy(other.data, other.data + size, this->data);
    }
    
    // using copy and swap idiom
    Buffer& operator=(Buffer other) {
        std::cout << "copy and swap assignment operator called" << std::endl;
        swap(*this, other);
        return *this;
    }
    
    ~Buffer() {
        std::cout << "destructor is called" << std::endl;
        delete[] data;
    }
};

int main() {
    Buffer b1{5};
    Buffer b3{10};
    b3 = b1; 
    return 0; 
}
    
    

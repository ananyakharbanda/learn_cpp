#include <iostream>

class Buffer {
public:
    int* data;
    size_t size;
    
public:
    Buffer(size_t n) : data{new int[n]}, size{n} {
        std::cout << "constructor called" << std::endl;
    }
    
    Buffer(const Buffer& other) {
        std::cout << "copy constructor called" << std::endl;
        this->size = other.size;
        this->data = new int[size];
        std::copy(other.data, other.data + size, this->data);
    }
    
    Buffer(Buffer&& other) noexcept {
        std::cout << "move constructor called" << std::endl;
        this->size = other.size;
        this->data = other.data;
        other.data = nullptr;
        other.size = 0;
    }
    
    Buffer& operator=(Buffer&& other) noexcept {
        std::cout << "move operator called" << std::endl;
        if (this == &other) {
            return *this;
        }
    
        delete[] data;
        
        this->data = other.data;
        this->size = other.size;    
        other.data = nullptr;
        other.size = 0;
        
        return *this;
    }
};

Buffer make() {
    Buffer temp(5);
    return temp;
}

int main() {
    Buffer a = make(); // NRVO here
    Buffer b(10);
    std::cout << b.data[0] << std::endl;
    Buffer c = std::move(b);
    std::cout << b.data[0] << std::endl;
    return 0;
}   

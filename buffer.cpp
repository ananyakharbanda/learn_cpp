#include <iostream>

class Buffer {
    int* data;
    size_t size;
public:
    Buffer(size_t n) : size{n}, data{new int[n]} {
        std::cout << "constructor: allocated " << n << " ints" << std::endl;
        for (int i=0; i<size; i++) {
            data[i] = i;
        }
    }
    Buffer(const Buffer& rhs) {
        std::cout << "deep copy constructor called" << std::endl;
        this->data = new int[rhs.size];
        std::copy(rhs.data, rhs.data + size, data);
    }
    
    Buffer& operator=(const Buffer& other) {
        std::cout << "called copy assignment" << std::endl;
        
        if (this == &other) return *this;
        delete[] data;
        
        size = other.size;
        data = new int[size];
        std::copy(other.data, other.data + size, data);
            
        return *this;
    }
        
    ~Buffer() {
        std::cout << "destructor: freeing memory" << std::endl;
        delete[] data;
    }
    int& operator[](size_t i) {
        return data[i];
    }
};

int main() {    
    Buffer a(5);
    Buffer b = a;
    a = b;
    
    b[0] = 99;
    return 0;
}



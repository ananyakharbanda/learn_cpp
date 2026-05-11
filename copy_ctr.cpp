#include <iostream>

class Device {
    int id;
    
public:
    Device(int x) : id{x} {
        std::cout << "constructor is called: " << id << std::endl;
    }

    Device(const Device& rhs) {
        this->id = rhs.id;
        std::cout << "copy constructor is called: " << id << std::endl;
    }
    
    int getId() const {
        return this->id;
    }
};

int main() {
    Device d{10};
    Device d1{15};
    Device d2{d};   
    Device d3{d1};
    Device d4{20};
    d4 = d1;
    std::cout << &d4 << " " << &d1 << std::endl;
    std::cout << d4.getId() << std::endl;
    return 0;
}
    

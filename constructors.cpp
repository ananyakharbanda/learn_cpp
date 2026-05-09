#include <iostream>
#include <string>
    
class Person {
    std::string name_;
    int age_;
    
public:
    Person() : name_("unknown"), age_(0) {
        std::cout << "default called" << std::endl;
    }
    
    Person(std::string n, int a) : name_(n), age_(a) {
        std::cout << "parameterized constructor " << name_ << "\n";
    }
    
    Person(std::string n) : Person(n, 0) {
        std::cout << "delegated constructor " << std::endl;
    }
    
    ~Person() {
        // basically like clean up
        std::cout << "object is destructed" << std::endl;
    }
};

int main() {
    Person p1;
    Person p2{"ananya", 19};
    Person p3{"papa"};
    Person* p4 = new Person();
    delete p4;
    return 0;
}

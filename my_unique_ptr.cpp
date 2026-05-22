#include <iostream>
#include <memory>
#include <string>

struct Resource {
    std::string name;
    Resource(std::string n) : name{n} { 
        std::cout << "Resource(" << name << ") created" << std::endl;
    }
    ~Resource() {
        std::cout << "Resource(" << name << ") destroyed" << std::endl;
    }
    void use() {
        std::cout << "using " << name << std::endl;
    }
};

void do_something(Resource& r) {
    r.use(); 
}

template <typename T>

class my_unique_ptr {
    T* t_;

public:
    my_unique_ptr(std::string n) {
        t_ = new T{n};
    }
    
    ~my_unique_ptr() {
        delete t_;
    }

    T* operator->() {
        return t_;
    }
}; 


int main() {
    // Resource* r = new Resource{"ananya"};
    std::unique_ptr<Resource> p1 = std::make_unique<Resource>("A");
    p1->use();
 
    // delete r;

    my_unique_ptr<Resource> r1{"papa"};
    r1->use();
    return 0;
} 


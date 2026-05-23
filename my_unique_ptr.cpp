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
    
    my_unique_ptr(const my_unique_ptr& rhs) = delete; // tell the compiler not to copy  
    
    my_unique_ptr(my_unique_ptr&& other) {
        t_ = other.t_;
        other.t_ = nullptr;
    }
    
    my_unique_ptr& operator=(my_unique_ptr&& other) {
        t_ = other.t_;
        other.t_ = nullptr;
        return *this;
    }
    
    T* get() {
        return t_;
    } 
    T* operator->() {
        return t_;
    }
}; 


int main() {
    // Resource* r = new Resource{"ananya"};
    std::unique_ptr<Resource> p1 = std::make_unique<Resource>("A"); // only use for objects made on heap
    std::unique_ptr<Resource> p2 = std::move(p1);
    // p1->use();
    std::unique_ptr<Resource> p3 = std::make_unique<Resource>("p3 made");
    p1 = std::move(p3);
 
    p2->use();

    Resource* rc1 = new Resource{"testing resource"};
    Resource rc2{"stack resource"};
    
    // std::unique_ptr<Resource> p3(&rc2); 
    // p3->use();
 
    // delete r;

    my_unique_ptr<Resource> r1{"papa"};
    my_unique_ptr<Resource> r2 = std::move(r1);
    my_unique_ptr<Resource> r3{"hello r3"};
    r1 = std::move(r3);
    r2->use();
    return 0;
} 


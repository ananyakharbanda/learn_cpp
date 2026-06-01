#include <iostream>
#include <memory>

struct Node {
    int v;
    Node(int val) : v(val) {
        std::cout << "node (" << v << ") created" << std::endl;
    }
    ~Node() {
        std::cout << "node(" << v << ") destroyed" << std::endl;
    }
    void print_val() {
        std::cout << "value = " << v << std::endl;
    }
};

int main() {
    std::shared_ptr<Node> a = std::make_shared<Node>(42);
    std::cout << "count: " << a.use_count() << std::endl;
    a->print_val(); 
    std::shared_ptr<Node> b = a;
    std::shared_ptr<Node> c = a;
    
    std::cout << "count: " << a.use_count() << std::endl;
    std::cout << "same object: " << (a.get() == b.get()) << std::endl;
    
    b.reset();
    std::cout << "count: " << a.use_count() << std::endl;
    
    {
        std::shared_ptr<Node> d = c;
        std::cout << "count: " << a.use_count() << std::endl;
    }
    
    std::cout << "count: " << a.use_count() << std::endl;
    c.reset();
    a.reset();
    std::cout << "after all resets" << std::endl;
}


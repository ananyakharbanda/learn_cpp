#include <iostream>

class BadBase {
public:
    virtual ~BadBase() {
        std::cout << "bad base destructor called" << std::endl;
    }
};

class BadDerived : public BadBase {
public:
    BadDerived(int n) : BadBase() {
        m = new int[n];
    }
    
    ~BadDerived() {
        std::cout << "bad derived destructor called" << std::endl;
    }
private:
    int* m;
};

int main() {
    BadBase* bb1 = new BadDerived(5);
    BadDerived* bd1 = new BadDerived(5);
    delete bb1;
    delete bd1;
    return 0;
}
    

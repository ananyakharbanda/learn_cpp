#include <iostream>
class Dummy {

public:
    int a;
    mutable int b;
    void change() const {
        // a = a + 2; // this is an error, const method cannot change
        b = b + 3; // this is ok, b is mutable
    }
};

int main() {
    Dummy d;
    std::cout << d.a << " " << d.b << std::endl;
    d.change();
    std::cout << d.a << " " << d.b << std::endl;
    return 0;
}

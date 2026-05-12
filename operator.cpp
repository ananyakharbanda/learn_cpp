#include <iostream>
#include <string>

class TestOperatorOverload {
    std::string a;
    std::string b;
public:
    TestOperatorOverload(const std::string& x, const std::string& y) : a{x}, b{y} {}
    std::string add() {
        return a + b;
    }
    
    std::string operator+(const std::string& prefix) {
        return prefix + a + b;
    }
};

int main() {
    TestOperatorOverload t{"a", "b"};
    std::cout << t + "this is the prefix"  << std::endl;
    return 0;
}

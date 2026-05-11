#include <iostream>

class Trap {
    int a;
    int b;
    
public:
    Trap(int x, int y): a{b}, b{x} {
        // this is wrong, gives incorrect output
        std::cout << a << " " << b << std::endl;
    }
};
    
int main() {
    Trap t{1, 2};
    return 0;
}

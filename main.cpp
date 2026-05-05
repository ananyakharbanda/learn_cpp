#include <iostream>
#include <cstdint>

int main() {
    int x = 10;
    int& r = x;
    int y = 20;
    r = y;
    
    std::cout << &x << std::endl;
    std::cout << &r << std::endl;
    std::cout << x << std::endl;
    std::cout << r << std::endl;
    std::cout << &x << std::endl;
    std::cout << &r << std::endl;
    return 0;
}
	

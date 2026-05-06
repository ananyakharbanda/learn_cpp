#include <iostream>
#include <cstdint>

int main() {
    double d = 3.14;
    
    // downcasting, narrowing conversion,  upto you to check
    int i = static_cast<int>(d);
    std::cout << i << std::endl;
    
    // upcasting, widening conversion, always safe 
    float f = static_cast<float>(d);
    std::cout << f << std::endl;
    
    // in pointers does not compile, only compiles in inheritance chain
    // double* b = d;
    // int* output = static_cast<int*>(b);
    // std::cout << output << std::endl;   

    return 0;
} 

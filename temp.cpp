#include <iostream>

template <typename T>
struct check{
    static bool isInt = false;
};

template <>
struct check<int>{
    static bool isInt = true;
};
    
int main(){
    std::cout << check<int>::isInt << std::endl;
    std::cout << check<double>::isInt << std::endl;
    return 0;
}

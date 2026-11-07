#include <iostream>
#include <cstring>

int main() {
    char* my_name = new char[7];
    strcpy(my_name, "ananya");
    std::cout << my_name << std::endl;
    delete[] my_name;
} 

#include <variant>
#include <vector>
#include <string>
#include <iostream>

void print_type(const std::vector<std::variant<int, std::string>>& elems) {
    for (const auto& e : elems) {
        if (std::holds_alternative<int>(e)) {
            std::cout << "int: " << std::get<int>(e) << std::endl;
        } else if (std::holds_alternative<std::string>(e)) {
            std::cout << "string: " << std::get<std::string>(e) << std::endl;
        }
    }
}
   

int main() {
    std::vector<std::variant<int, std::string>> v = {42, "hi", 7};
    print_type(v);
} 
        

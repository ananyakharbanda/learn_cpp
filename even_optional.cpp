#include <optional>
#include <iostream>
#include <vector>

std::optional<int> first_even(const std::vector<int>& v) {
    for (int i : v) {
        if (i % 2 == 0) {
            return i;
        }
    }
    return std::nullopt;
}

int main() {
    std::vector<int> v1 = {3, 5, 7, 8, 9};
    if (first_even(v1).has_value()) {
        std::cout << first_even(v1).value() << std::endl;
    } else {
        std::cout << "no value" << std::endl;
    }
    
    std::vector<int> v2 = {1, 3, 5};    
    if (first_even(v2).has_value()) {
        std::cout << first_even(v2).value() << std::endl;
    } else {
        std::cout << "no value" << std::endl;
    }
}

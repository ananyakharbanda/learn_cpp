#include <iostream> 
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

int main() {
    std::vector<std::string> v = {"pear", "fig", "apple", "kiwi", "fig", "plum", "banana", "date"};
    
    std::sort(v.begin(), v.end(), [](const std::string& a, const std::string& b) {
        if (a.size() != b.size()) {
            return a.size() < b.size();
        }
    
        return a < b;
    });
    
    for (const auto& f : v) {
        std::cout << f << ": " << f.size() << std::endl;
    }
}

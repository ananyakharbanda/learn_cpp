#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


int main() {
    std::vector<std::string> words = {
        "apple", "banana", "apple", "cherry",
        "banana", "apple", "date", "cherry", "apple"
    };
    
    std::unordered_map<std::string, int> freq;
    for (const auto& w : words) {
        freq[w]++;
    }
    
    std::vector<std::pair<std::string, int>> sorted(freq.begin(), freq.end());
    std::sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b){ return a.second > b.second; });
    
    for (const auto& p : sorted) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
}
        

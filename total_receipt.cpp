#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

int main() {
    std::vector<std::pair<std::string, int>> purchases = {{"coffee", 4}, {"bagel", 3}, {"coffee", 4}, {"juice", 5}, {"bagel", 3}};
    std::map<std::string, int> total_map;
    
    for (const auto& purchase : purchases) {    
        total_map[purchase.first] += purchase.second;
    }
    
    std::vector<std::pair<std::string, int>> sorted_total;
    for (const auto& item : total_map) {  
        sorted_total.push_back(item);
    }
    
    std::sort(sorted_total.begin(), sorted_total.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) 
            return a.second < b.second;
        return a.first < b.first;
    });

    int final_total = 0;
    
    for (const auto& total : sorted_total) {
        std::cout << total.first << ": " << total.second << std::endl;
        final_total += total.second;
    }
    
    std::cout << "Total: " << final_total << std::endl;
    
    return 0;
}
    
    

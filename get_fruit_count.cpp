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

        /* if(freq.find(w) == freq.end()){
            std::pair<std::string, int> p;
            p.first = w;
            p.second = 1;
            freq.insert(p);
        }
        else{
            int cval = freq[w]; 
            freq[w] = cval + 1;
        } */
    }
    
    std::vector<std::pair<std::string, int>> sorted(freq.begin(), freq.end());
    std::sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b){ return a.second > b.second; });
    for (const auto& p : sorted) {
        std::cout << p.first << ", " << p.second << std::endl;
    }
}
    
    

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

int main() {
    std::vector<int> nums = {5, 4, 3, 6, 7, 5, 9, 8, 3, 2, 2};
    std::map<int, int> sorted_nums;
    for (int n : nums) {
        sorted_nums[n]++;
    }
    
    std::vector<std::pair<int, int>> result(sorted_nums.begin(), sorted_nums.end());
    
    for (const auto& p : result) {
        std::cout << p.first << ", " << p.second << std::endl;
    }
    
    // std::set<int> unique_nums(nums.begin(), nums.end());
    
    // for (int n : unique_nums) {
    //     std::cout << n << std::endl;
    // }
    
    return 0;
}

#include <vector>
#include <algorithm>
#include <iostream>
#include <array>
#include <map>

template<typename InputIt, typename T>
T my_accumulate(InputIt begin_it, InputIt end_it, T t) {
    T temp = t;
    while (begin_it != end_it) {
        temp += *begin_it;
        begin_it++;
    }
    return temp;
}

int main() {
    std::vector<int> nums = {1, 5, 3, 6, 7, 8, 2, 9, 10};
    const auto val = my_accumulate(nums.begin(), nums.end(), 0);
    std::cout <<  val << std::endl;
   
    std::array<std::pair<int, int>, 10> id_age;
    for (int i = 0; i < 10; i++) {
        std::pair<int, int> p;
        p.first = i;
        p.second = i*i; 
        id_age[i] = p; 
    }
    
    std::map<int, int> sorted(id_age.begin(), id_age.end());
    
    for (int i = 0; i < 10; i++) {
        sorted[id_age[i].first] = id_age[i].second;
    }
    
    auto begin_it = sorted.begin();
    const auto end_it = sorted.end(); 
    while(begin_it != end_it) { 
        std::cout << (*begin_it).first << ", " << (*begin_it).second << std::endl;
        begin_it++;
    }

    return 0;
}
    
    

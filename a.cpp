#include <vector>
#include <iostream>
#include <algorithm>


/*int sum(int a, int b){
    return a + b;
}*/

template<typename T1, typename T2> 
T1 sum(T1 a, T2 b){
    return a + b;
}

int main() {

    int a = 10;
    int b = 20;

    std::cout << sum(a, b) << std::endl;

    std::vector<int> v;
    v.push_back(1);
    v.push_back(71);
    v.push_back(11);
    v.push_back(91);
    // v.sort();
    std::sort(v.begin(), v.end());

    // std::cout << v << std::endl;
    for (int i =  0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }

    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << std::endl;
    }
    
    for (auto x : v) {
        std::cout << x << std::endl;
    }

    return 0;
}

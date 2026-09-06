#include <iostream>
#include <vector>
#include <algorithm>

template<typename IT, typename V>
IT my_find(IT& s, const IT& e, V v){
    while(s != e){
        if(*s == v){
            return s;
        }
        s++;
    }
    return e;
}
        

int main(){
    std::vector<int> v = {3,4,6,7,2};
    //std::vector::const_iterator ci = v.cbegin();
    auto ci = v.begin();
    const auto& ce = v.cend();

    while(ci != ce) {
        std::cout << *ci << std::endl;
        ci++;
    }
    
    ci = v.begin();

    const auto& fi = my_find(ci, v.begin()+2, 7);

    std::cout << *fi << std::endl;

    return 0;
}

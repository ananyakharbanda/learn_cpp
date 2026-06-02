#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main() {
    std::vector<int> v = {10, 20, 30, 40, 50};
   
    // basic operations 
    std::vector<int>::iterator it = v.begin();
    std::vector<int>::iterator end = v.end();
    
    std::cout << *it << std::endl;
    ++it;
    std::cout << *it << std::endl;

    // random access (vector only)
    std::vector<int>::iterator it2 = v.begin();
    std::cout << it2[2] << std::endl;
    std::cout << *(it2+3) << std::endl;
    std::cout << (v.end() - v.begin()) << std::endl;
    
    // std::advance, works on any iterator category
    std::list<int> lst = {1, 2, 3, 4, 5};
    std::list<int>::iterator lit = lst.begin();
    std::advance(lit, 3);
    std::cout << *lit << std::endl;
    std::advance(lit, -1);
    std::cout << *lit << std::endl;

    // std::distance
    std::list<int>::iterator a = lst.begin();
    std::list<int>::iterator b = lst.end();
    std::cout << std::distance(a, b) << std::endl;
    
    // std::next / std::prev: non-mutating advance
    std::vector<int>::iterator first = v.begin();
    std::vector<int>::iterator third = std::next(first, 2); // returns new iterator, doesn't change first 
    std::vector<int>::iterator last = std::prev(v.end(), 1); // one before end
    
    // const iterators
    std::vector<int>::const_iterator cit = v.cbegin();
    std::cout << *cit << std::endl;
    // *cit = 99 // ERROR: const iterator, can't write
    
    for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
        std::cout << *rit << std::endl;
    }
}
    
    
    

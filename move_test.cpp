#include <iostream>
#include <cstring>

class MyMovable {
    char* name;
    
public:
    MyMovable(const std::string& n) {
        name = new char[n.length() + 1];
        std::copy(n.c_str(), n.c_str() + n.length(), name);
        name[n.length()] = '\0';
    }
    
    // MyMovable(MyMovable&& other) {
    //     this->name = other.name;
    //     other.name = nullptr;
    // }
    
    MyMovable(MyMovable&& other) = delete; // not allowed to move at all

    MyMovable(const MyMovable& other) {
        name = new char[strlen(other.name) + 1];
        std::copy(other.name, other.name + strlen(other.name), name);
        name[strlen(other.name)] = '\0';
    }
    
    ~MyMovable() {
        delete []name;
    }
};

MyMovable&& mymove(MyMovable& m) { // equals to std::move
    return static_cast<MyMovable&&>(m);
}

template<typename T>
T&& mymove(T& t)
{
    return static_cast<T&&>(t);
}

int main() {
    MyMovable m{"ananya"};
    MyMovable movem = mymove(m);
    MyMovable copym = movem; 
    return 0;
}
     
           

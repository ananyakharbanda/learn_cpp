#include <iostream>
#include <string>


template<typename... T>
void print_var_args(T&... args) {
    ((std::cout << args << ' '), ...);
    std::cout <<'\n';
}

template<typename T>
void print_var_rec(T tail) {
    std::cout << tail << '\n';
}    

template<typename H, typename...T>
void print_var_rec(H& head, T&... tail) {
    std::cout << head << '\n';
    print_var_rec(tail...);
}

int main() {
    int x = 10;
    double d = 10.5;
    std::string name = "ananya";
    char c = 'x';
    print_var_rec(x, d, name, c);
}

#include <iostream>

class Shape {
public:
    virtual void draw() const = 0;
    Shape() {}
};

class Square : public Shape {
public: 
    void draw(int x) const {
        std::cout << "draw" << std::endl;
    }

    void draw() const {
        std::cout << "base draw" << std::endl;
    }

    Square() {}
};

int main() {
    Square sq1{};
    sq1.draw(1);
    Shape& s1 = sq1;
    s1.draw();
    Shape* s2 = new Square{};
    s2->draw();
    return 0;
}  

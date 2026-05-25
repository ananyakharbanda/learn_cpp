#include <iostream>
#include <vector>

class Shape {
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Circle" << std::endl;
    }
    double radius() const {
        return 5.0; 
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Rectangle" << std::endl;
    }
    double width() const {
        return 4.0;
    }
};

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle());
    shapes.push_back(new Rectangle());
    shapes.push_back(new Circle());
    std::vector<Shape&> shapes2;
    Circle c1{};
    shapes2.push_back(std::move(c1));
 
    for (const Shape* s : shapes) {
        s->draw();
        if (const Circle* c = dynamic_cast<const Circle*>(s)) {
            std::cout << "radius: " << c->radius() << std::endl;
        }
        if (const Rectangle* r = dynamic_cast<const Rectangle*>(s)) {
            std::cout << " width: " << r->width() << std::endl;
        }
    }
    
    Shape* s = new Circle();
    std::cout << typeid(*s).name() << std::endl;
    std::cout << (typeid(*s) == typeid(Circle)) << std::endl;
    
    try {
        Circle& c = dynamic_cast<Circle&>(*s);
        std::cout << "it's a circle!" << std::endl;
    } catch (const std::bad_cast& e) {
        std::cout << "it's not a circle!" << std::endl;
    }
    
    delete s;
}



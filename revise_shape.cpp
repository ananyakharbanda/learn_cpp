#include <iostream>

class Shape {
public:
    virtual double area()  const = 0;
    virtual void   print() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape {
    double radius_;
public:
    explicit Circle(double r) : radius_{r} {}

    double area() const override {
        return 3.14 * radius_ * radius_;
    }

    void print() const override {
        std::cout << "circle(r=" << radius_ << " | area=" << area() << ")" << std::endl;
    }
};

class Rectangle : public Shape {
    int width_;
    int height_;
public:
    Rectangle(int w, int h) : width_{w}, height_{h} {}

    double area() const override {
        return width_ * height_;
    }

    void print() const override {
        std::cout << "rectangle(" << width_ << "x" << height_ << ", area=" << area() << ")" << std::endl;
    }
};

class Items {
    Shape** items_;
    int     size_;
    int     capacity_;

public:
    Items(int n) : items_{new Shape*[n]}, size_{0}, capacity_{n} {}

    // copy constructor
    Items(const Items& other) {
        items_    = new Shape*[other.capacity_];
        size_     = other.size_;
        capacity_ = other.capacity_;
        for (int i = 0; i < size_; i++)
            items_[i] = other.items_[i];  // shallow for now
    }

    // move constructor
    Items(Items&& other) {
        items_    = other.items_;
        size_     = other.size_;
        capacity_ = other.capacity_;
        other.items_    = nullptr;
        other.size_     = 0;
        other.capacity_ = 0;
    }

    ~Items() {
        for (int i = 0; i < size_; i++)
            delete items_[i];
        delete[] items_;
    }

    void add(Shape* s) {
        items_[size_++] = s;
    }

    friend std::ostream& operator<<(std::ostream& os, const Items& c) {
        for (int i = 0; i < c.size_; i++)
            c.items_[i]->print();
        return os;
    }
};

int main() {
    Items i(4);
    i.add(new Circle(5.0));
    i.add(new Rectangle(4, 6));
    std::cout << i;
    return 0;
}

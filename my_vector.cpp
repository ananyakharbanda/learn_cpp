#include <iostream>
#include <cmath>

class Vector {
    double x_, y_;

public:
    Vector(double x=0, double y=0) : x_{x}, y_{y} {}
    
    Vector operator+(const Vector& other) const {
        Vector v{other.x_ + x_, other.y_ + y_};
        return v;
    }
    
    Vector operator-(const Vector& other) const {
        Vector v{x_ - other.x_, y_ - other.y_};
        return v;
    }
    
    Vector operator*(double scalar) const {
        Vector v{x_ * scalar, y_ * scalar};
        return v;
    }
    
    Vector operator-() const{
        Vector v{-x_, -y_};
        return v;
    }
    
    Vector& operator+=(const Vector& other) {
        x_ += other.x_;
        y_ += other.y_;
        return *this;
    }
    
    bool operator==(const Vector& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }
    
    double operator*(const Vector& other) const {
        return x_ * other.x_ + y_ * other.y_;
    }
    
    double length() const {
        return std::sqrt(x_*x_ + y_*y_);
    }
    
    explicit operator bool() const {    
        return length() > 0;
    }

    bool isGTZ() const {
        return length() > 0;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Vector& v) {
        return os << '(' << v.x_ << ", " << v.y_ <<')';
    }
    
};

int main() {
    Vector a{3,4};
    Vector b{1,2};
    
    Vector c = a + b;
    Vector d = a * 2.0;
    // Vector e = 3.0 * a;
    
    std::cout << a << '\n';
    std::cout << c << '\n';
    std::cout << a.length() << '\n';
    
    if (a) std::cout << "non-zero\n";
    if (a.isGTZ()) std::cout << "non-zero\n";
    
    a += b;
    std::cout << a << std::endl;
    return 0;
}

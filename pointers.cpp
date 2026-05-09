#include <iostream>

class Point {
    public: 
        int x_;
        int y_;
        int z_;
        Point(int x, int y) {
            x_ = x;
            y_ = y;
        }
};

int main() {
    Point* r = new Point{1, 2};
    Point* s = r;
    Point p = {6, 7};
    std::cout << sizeof(p) << std::endl;

    delete r; 
    s = nullptr; 
    if (s != nullptr) {
        std::cout << s->x_ << " " << s->y_ << std::endl;
    } else {
        std::cout << "null";
    }
    return 0;
}

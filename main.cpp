#include <iostream>
#include <cstdint>

class Student{
    public:
        Student(){
        }
        void check_result() { }
    private:
        int age_;
};

void check_result(const Student& s){
   Student& temp = const_cast<Student&>(s);
   temp.check_result(); 
}

int main() {
    Student s;
    check_result(s);
    return 0;
}

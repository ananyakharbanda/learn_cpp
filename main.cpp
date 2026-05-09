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

int anything(int a, int b, double c) { return 0; }

int main() {
    // Student s;
    // check_result(s);
   
    int arr[5] = {10, 20, 30, 40, 50};
    
    const char* s = "hello";
    std::cout << s[1] << std::endl;
     
     
    return 0; 
}

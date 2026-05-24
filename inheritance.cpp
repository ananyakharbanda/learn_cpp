#include <string>
#include <iostream>

class Animal {
public:
    std::string name;   
    int id;
    Animal(std::string n, int i, std::string d) : name{n}, id{i}, dob{d} { 
        age = 1;
    }
protected:
    std::string dob;
    int age;
};

class Dog : public Animal {
public:
    std::string breed;
    Dog(std::string n, int i, std::string b, std::string d) : Animal(n, i, d) {
        breed = b;
    }
    std::string getDob() {
        age++;
        return dob;
    }
};

class Dog2 : protected Animal {
public:
    std::string breed;
    Dog2(std::string n, int i, std::string b, std::string d) : Animal(n, i, d) {
        breed = b;
    }
    std::string getDob() {
        age++;
        return dob;
    }
};

int main() {
    Dog d1{"dog1", 1, "golden retriever", "2707"};
    Dog2 d2{"dog2", 2, "german shepherd", "0101"};
    std::cout << d1.getDob() << std::endl;
    std::cout << d2.getDob() << std::endl;
    Animal a1{"animal1", 3, "1212"};
    a1.age++;
    return 0;
}

    


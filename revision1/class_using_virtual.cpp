#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Animal {
public:
    virtual void speak() const = 0;

    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void speak() const override {
        cout << "Woof\n";
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        cout << "Meow\n";
    }
};

class Cow : public Animal {
public:
    void speak() const override {
        cout << "Moo\n";
    }
};

void makeSpeak(const Animal& animal) {
    animal.speak();
}

int main() {
    Dog dog;
    Cat cat;

    makeSpeak(dog);
    makeSpeak(cat);

    vector<unique_ptr<Animal>> animals;

    animals.push_back(make_unique<Dog>());
    animals.push_back(make_unique<Cat>());
    animals.push_back(make_unique<Cow>());

    for (const auto& animal : animals) {
        animal->speak();
    }
}

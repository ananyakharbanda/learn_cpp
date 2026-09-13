#include <string_view>
#include <string>
#include <iostream>

int count_vowels(std::string_view s) {
    int vowels = 0;
    for (const char& c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels += 1;
        }
    }
    return vowels;
}

int main() {
    std::cout << count_vowels("hello world") << std::endl;
    std::cout << count_vowels("xxx") << std::endl;
    std::cout << count_vowels("aeiou") << std::endl;
}
            

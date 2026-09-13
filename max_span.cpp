#include <iostream>
#include <span>
#include <vector>

int max_of(std::span<const int> xs) {
    int max = xs[0];

    for (std::size_t i = 1; i < xs.size(); ++i) {
        if (xs[i] > max) {
            max = xs[i];
        }
    }

    return max;
}

int main() {
    std::vector<int> v = {4, 2, 9, 1};
    int arr[] = {5, 5, 5};

    std::cout << max_of(v) << '\n';

    std::span<const int> sub = std::span{v}.subspan(1);
    std::cout << max_of(sub) << '\n';

    std::cout << max_of(arr) << '\n';
}

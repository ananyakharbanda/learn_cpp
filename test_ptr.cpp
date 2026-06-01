#include <iostream>
#include <memory>

struct Widget {
    int id;
    explicit Widget(int i) : id(i) {
        std::cout << "  Widget(" << id << ") constructed\n";
    }
    ~Widget() {
        std::cout << "  Widget(" << id << ") destroyed\n";
    }
};

// unique_ptr must be taken by move — there is only ever one owner
void do_something(std::unique_ptr<Widget> x) {
    std::cout << "  do_something(unique): id = " << x->id << "\n";
    // x destructs here — Widget dies at end of this call
}

// shared_ptr can be copied freely — just bumps ref_count
void do_something(std::shared_ptr<Widget> y) {
    std::cout << "  do_something(shared): id = " << y->id
              << ", use_count inside = " << y.use_count() << "\n";
    // y destructs here — ref_count drops back after the call
}

int main() {
    std::unique_ptr<Widget> a = std::make_unique<Widget>(1);
    std::shared_ptr<Widget> b = std::make_shared<Widget>(2);

    std::cout << "\n--- unique_ptr: must std::move, ownership transfers ---\n";
    do_something(std::move(a));
    std::cout << "  a empty after move? " << (a == nullptr ? "yes" : "no") << "\n";

    std::cout << "\n--- shared_ptr: copy is fine, ref_count goes up then back down ---\n";
    std::cout << "  use_count before call = " << b.use_count() << "\n";
    do_something(b);
    std::cout << "  use_count after call  = " << b.use_count() << "\n";
    std::cout << "  b still valid?        " << (b ? "yes" : "no") << "\n";

    std::cout << "\n--- end of main: b destructs here ---\n";
}

#include <iostream>
#include <vector>
#include <thread>
#include <syncstream>

const int threads = 8;
const int lines = 10000;

bool use_sync = true;

void print_lines(int id) {
    for (int i = 0; i < lines; i++) {
        if (use_sync) {
            std::osyncstream(std::cout) << "thread: " << id << " line " << i << "\n";
        } else {
            std::cout << "thread: " << id << " line " << i << "\n";
        }
    }
}

int main() {
    std::thread t1(print_lines, 1);
    std::thread t2(print_lines, 2);
    std::thread t3(print_lines, 3);
    std::thread t4(print_lines, 4);
    std::thread t5(print_lines, 5);
    std::thread t6(print_lines, 6);
    std::thread t7(print_lines, 7);
    std::thread t8(print_lines, 8);
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
}

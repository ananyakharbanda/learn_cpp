#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

int incrementer(int &x) {
    int i = 0;
    std::lock_guard<std::mutex> lk(mtx);
    while (i != 10) {
        {
            std::cout << "running on thread " << std::this_thread::get_id() << std::endl;
            // std::lock_guard<std::mutex> lk(mtx);
            int j = 1;
            i += 1;
            while (j % 10'001 != 0) {
                x += 1;
                j += 1;
            }
        }
    }
    std::cout << x << std::endl;
    return x;
}

int main() {
    int p = 0;
    std::thread t(incrementer, std::ref(p));
    std::thread t2(incrementer, std::ref(p));
    std::cout << "in main" << std::endl;

    t.join();
    t2.join();
    std::cout << p << std::endl;
    return 0; 
}

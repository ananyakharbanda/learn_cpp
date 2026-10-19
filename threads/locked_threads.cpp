#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <sched.h>
#include <chrono>

std::mutex mtx;

void print_thread_info() {
    std::lock_guard<std::mutex> lk(mtx);
    
    std::cout << "std::thread id: " << std::this_thread::get_id() << std::endl;
    
    pid_t tid = gettid();
    std::cout << "gettid(): " << tid << std::endl;
    
    int cpu = sched_getcpu();
    std::cout << "running on CPU " << cpu << std::endl;
    
    std::this_thread::sleep_for(std::chrono::seconds(30));
} 


int main() {
    std::thread t1(print_thread_info);
    
    std::thread t2(print_thread_info);
    
    std::thread t3(print_thread_info);
    
    std::thread t4(print_thread_info);
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

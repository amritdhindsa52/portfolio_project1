#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>


std::mutex mtx;

void countUp() {
    for (int i = 0; i <= 20; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Counting up: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
    }
}

void countDown() {
    for (int i = 20; i >= 0; --i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Counting down: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
    }
}

int main() {
    std::thread t1(countUp);

    // count back from 20 to 0
    t1.join();

    std::thread t2(countDown);
    t2.join();

    return 0;
}

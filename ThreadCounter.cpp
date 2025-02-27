#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx; // Mutex for thread synchronization

void countUp(int max) {
    for (int i = 0; i <= max; i++) {
        lock_guard<mutex> lock(mtx);
        cout << "Counting Up: " << i << std::endl;
    }
}

void countDown(int max) {
    for (int i = max; i >= 0; i--) {
        lock_guard<mutex> lock(mtx);
        cout << "Counting Down: " << i << std::endl;
    }
}

int main() {
    thread thread1(countUp, 20);
    thread1.join(); // Ensure thread1 completes before starting thread2

    thread thread2(countDown, 20);
    thread2.join(); // Wait for thread2 to complete

    return 0;
}

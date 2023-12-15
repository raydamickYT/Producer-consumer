#include <queue>
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

int counter = 0;
bool done = false;
std::mutex mtx;
std::condition_variable cv;

std::queue<int> goods;

void producer() {
    std::cout << "Starting producer..." << std::endl;

    for (int i = 0; i < 500; ++i) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            goods.push(i);
            counter++;
        }
        cv.notify_one(); // Notify consumer
    }

    {
        std::lock_guard<std::mutex> lock(mtx);
        done = true;
    }
    cv.notify_one(); // Notify consumer that we're done

    std::cout << "Finished producer..." << std::endl;
}

void consumer() {
    std::cout << "Starting consumer..." << std::endl;

    std::unique_lock<std::mutex> lock(mtx);
    while (!done || !goods.empty()) {
        cv.wait(lock, [] { return done || !goods.empty(); });
        while (!goods.empty()) {
            goods.pop();
            counter--;
        }
    }

    std::cout << "Finished consumer..." << std::endl;
}

int main() {
    counter = 0;
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    std::cout << "Net: " << counter << " " << goods.size() << std::endl;
}

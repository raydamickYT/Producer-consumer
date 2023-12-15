#include <iostream>
#include <queue>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);
std::atomic<bool> done(false);
std::queue<int> goods;


void producer() {
    std::cout << "Starting producer...\n";

    for (int i = 0; i < 500; ++i) {
        goods.push(i);
        counter.fetch_add(1, std::memory_order_relaxed);
    }

    done.store(true, std::memory_order_release);
    std::cout << "Finished producer...\n";
}

void consumer() {
    std::cout << "Starting consumer...\n";

    while (!done.load(std::memory_order_acquire) || counter.load(std::memory_order_relaxed) > 0) {
        if (!goods.empty()) {
            goods.pop();
            counter.fetch_sub(1, std::memory_order_relaxed);
        }
    }

    std::cout << "Finished consumer...\n";
}
int main() {
    counter = 0;
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    std::cout << "Net: " << counter << " " << goods.size() << std::endl;
}

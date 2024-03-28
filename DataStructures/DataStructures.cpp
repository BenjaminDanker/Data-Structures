#include <iostream>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <stack>
#include <queue>


void deleteMiddleElement(std::queue<int>& queue, int range) {
    std::queue<int> tempQueue;

    for (int i = 0; i < range; i++) {
        tempQueue.push(queue.front());
        queue.pop();
    }
    queue.pop();
    while (!queue.empty()) {
        tempQueue.push(queue.front());
        queue.pop();
    }
    while (!tempQueue.empty()) {
        queue.push(tempQueue.front());
        tempQueue.pop();
    }
}

int main() {
    std::queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    std::queue<int> tempQueue = queue;
    std::cout << "Original Queue: ";
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    std::cout << std::endl;

    deleteMiddleElement(queue, 2);

    std::cout << "Modified Queue: ";
    while (!queue.empty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
    std::cout << std::endl;


    return 0;
}
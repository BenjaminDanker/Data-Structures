#include <iostream>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <stack>
#include <queue>


void deleteThirdElement(std::queue<int>& queue) {
    std::queue<int> tempQueue;
    int range = 1;

    for (int i = 0; i <= range; i++) {
        tempQueue.push(queue.front());
        queue.pop();
    }
    queue.pop();
    for (int i = 0; i <= range; i++) {
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

    deleteThirdElement(queue);

    std::cout << "Modified Queue: ";
    while (!queue.empty()) {
        std::cout << queue.front() << " ";
        queue.pop();
    }
    std::cout << std::endl;


    return 0;
}
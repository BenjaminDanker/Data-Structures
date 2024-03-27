#include <iostream>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <stack>


template <typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    CircularLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~CircularLinkedList() {
        while (!isEmpty()) {
            removeFront();
        }
    }

    bool isEmpty() const {
        if (size == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    int getSize() const {
        return size;
    }

    void addFront(const T& item) {
        Node* newNode = new Node(item);
        newNode->next = head;
 
        if (head != nullptr) {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        else {
            newNode->next = newNode;
            tail = newNode;
        }
        head = newNode;
    }

    void addBack(const T& item) {
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = tail = newNode;
            tail->next = head;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }


    void removeFront() {
        tail->next = head->next;
        delete head;
        head = tail->next;
    }


    void removeBack() {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        delete tail;
        tail = temp;
    }


    void print() const {
        Node* temp = head;
        if (head != nullptr) {
            do {
                std::cout << temp->data;
                if (temp->next != head) {
                    std::cout << "->";
                }
                temp = temp->next;
            } while (temp != head);
        }
        std::cout << std::endl;
    }
};

template <typename T>
class Queue {
private:
    CircularLinkedList<T> circularLinkedList;
public:
    void enqueue(const T& item) {
        circularLinkedList.addBack(item);
    }
    void dequeue() {
        circularLinkedList.removeFront();
    }
    void print() {
        circularLinkedList.print();
    }
};

int main() {
    Queue<int> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.print();

    queue.dequeue();
    queue.print();

    return 0;
}
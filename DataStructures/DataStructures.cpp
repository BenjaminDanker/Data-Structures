#include <iostream>
#include <vector>
#include <numeric>
#include <stdexcept>


template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <typename T>
class DoubleLinkedList {
private:
    Node<T>* begin;
    Node<T>* end;

    template <typename T>
    Node<T>* makeNode(T value) {
        Node<T>* newNode = new Node<T>;

        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        return newNode;
    }
public:
    DoubleLinkedList() : begin{ nullptr }, end{ nullptr } {}

    ~DoubleLinkedList() {
        Node<T>* del = begin;

        while (begin != nullptr) {
            begin = begin->next;
            delete del;
            del = begin;
        }
    }

    template <typename T>
    void addBack(T value) {
        Node<T>* newNode = makeNode(value);

        if (begin == nullptr) {
            begin = newNode;
            end = newNode;
        }
        else {
            newNode->prev = end;
            end->next = newNode;
            end = end->next;
        }
    }

    template <typename T>
    void addFront(T value) {
        Node<T>* newNode = makeNode(value);

        if (begin == nullptr) {
            begin = newNode;
            end = newNode;
        }
        else {
            newNode->next = begin;
            begin->prev = newNode;
            begin = newNode;
        }
    }

    void printForward() const {
        Node<T>* cur = begin;
        while (cur != nullptr) {
            std::cout << cur->data << std::endl;
            cur = cur->next;
        }

    }

    void printBackward() const {
        Node<T>* cur = end;
        while (cur != nullptr) {
            std::cout << cur->data << std::endl;
            cur = cur->prev;
        }
    }
};

int main() {
    DoubleLinkedList<int> list1;

    list1.addFront(1);
    list1.addFront(2);
    list1.addFront(3);
    list1.addBack(4);

    list1.printForward();
    std::cout << std::endl;
    list1.printBackward();


    std::cout << std::endl;


    DoubleLinkedList<std::string> list2;

    // compiler will assume (const char*) if passed in variables are not declared as string first no matter the length
    std::string one = "1";
    std::string two = "2";
    std::string three = "3";
    std::string four = "4";


    list2.addFront(one);
    list2.addFront(two);
    list2.addFront(three);
    list2.addBack(four);

    list2.printForward();
    std::cout << std::endl;
    list2.printBackward();
}
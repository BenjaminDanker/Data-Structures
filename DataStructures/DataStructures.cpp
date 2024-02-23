#include <iostream>
#include <vector>
#include <numeric>
#include <stdexcept>


struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    int count;
    Node* begin;

    Node* makeNode(const int value) {
        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = nullptr;

        return newNode;
    }
public:
    LinkedList() : count{ 0 }, begin{ nullptr } {}

    ~LinkedList() {
        Node* del = begin;

        while (begin != nullptr) {
            begin = begin->next;
            delete del;
            del = begin;
        }
    }

    void insert(int pos, int value) {
        if (pos < 0 || pos > count) {
            throw std::out_of_range("Position is out of range");
        }

        Node* add = makeNode(value);
        if (pos == 0) {
            add->next = begin;
            begin = add;
        }
        else {
            Node* cur = begin;

            for (int i = 1; i < pos; i++) {
                cur = cur->next;
            }
            add->next = cur->next;
            cur->next = add;
        }

        count++;
    }

    LinkedList mergeSortedLists(LinkedList& list2) {
        LinkedList list3;
        Node* cur1 = begin;
        Node* cur2 = list2.begin;

        int i = 0;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->data < cur2->data) {
                list3.insert(i, cur1->data);
                cur1 = cur1->next;

                i++;
            }
            else if(cur1->data > cur2->data) {
                list3.insert(i, cur2->data);
                cur2 = cur2->next;

                i++;
            }
            else if (cur1->data == cur2->data) {
                list3.insert(i, cur1->data);
                cur1 = cur1->next;
                i++;

                list3.insert(i, cur2->data);
                cur2 = cur2->next;
                i++;
            }
        };

        return list3;
    }

    void rearrangeLinkedList() {
        Node* prev = nullptr;
        Node* cur = begin;

        // set end to end of list
        Node* end = begin;
        while (end->next != nullptr) {
            end = end->next;
        }

        Node* newEnd = end;
        while (cur->data % 2 == 0 && cur != end) {
            newEnd->next = cur;
            cur = cur->next;

            newEnd->next->next = nullptr;
            newEnd = newEnd->next;
        }

        if (cur->data % 2 != 0) {
            begin = cur;

            while (cur != end) {
                if (cur->data % 2 != 0) {
                    prev = cur;
                    cur = cur->next;
                }
                else {
                    prev->next = cur->next;
                    cur->next = nullptr;

                    newEnd->next = cur;
                    newEnd = cur;
                    
                    cur = prev->next;
                }
            }
        }
        else {
            prev = cur;
        }

        if (newEnd != end && end->data % 2 == 0) {
            prev->next = end->next;
            end->next = nullptr;
            newEnd->next = end;
        }
    }

    void print() const {
        if (count == 0) {
            std::cout << "List is empty" << std::endl;
        }
        Node* cur = begin;
        while (cur != nullptr) {
            std::cout << cur->data << std::endl;
            cur = cur->next;
        }

    }
};

int main() {
    // Create the first linked list: 1->3->5->7
    LinkedList list1;

    list1.insert(0, 1);
    list1.insert(1, 3);
    list1.insert(2, 5);
    list1.insert(3, 7);

    // Create the second linked list: 2->4->6->8
    LinkedList list2;

    list2.insert(0, 2);
    list2.insert(1, 4);
    list2.insert(2, 6);
    list2.insert(3, 8);

    // Merge the two sorted lists
    LinkedList sortedList = list1.mergeSortedLists(list2);

    // Print the merged list
    std::cout << "Sorted List: " << std::endl;
    sortedList.print();



    // Create the linked list: 1 -> 2 -> 5 -> 8 -> 3 -> 6 -> 7 -> 4
    LinkedList list3;

    list3.insert(0, 1);
    list3.insert(1, 2);
    list3.insert(2, 5);
    list3.insert(3, 8);
    list3.insert(4, 3);
    list3.insert(5, 6);
    list3.insert(6, 7);
    list3.insert(7, 4);

    // Rearrange the list
    list3.rearrangeLinkedList();

    // Print the rearranged list
    std::cout << "Rearranged List: " << std::endl;
    list3.print();
}
#include <iostream>
#include <vector>
#include <numeric>
#include <stdexcept>


template <typename T> class MyVector {
private:
    T* arr;
    size_t size;
    size_t capacity;
public:
    MyVector() : arr{ nullptr }, size{ 0 }, capacity{ 0 } {};

    explicit MyVector(size_t initialCapacity) : arr{ nullptr }, capacity {initialCapacity} {
        arr = new T[capacity];
    }

    ~MyVector() {
        delete[] arr;
    }

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return(size == 0);
    }

    int& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        
        return arr[index];
    }

    template <typename T> void pushBack(T element) {
        if (size == capacity) {
            if (capacity == 0) {
                capacity = 1;
            }
            else {
                capacity = capacity * 2;
            }

            // create new array and copy elements
            int* newArr = new T[capacity];
            for (size_t i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }

        arr[size] = element;
        size++;
    }

    template <typename T> void insert(size_t index, T value) {
        if (size == capacity) {
            if (capacity == 0) {
                capacity = 1;
            }
            else {
                capacity = capacity * 2;
            }

            // create new array with elements before insert index
            int* newArr = new T[capacity];
            for (size_t i = 0; i < index; i++) {
                newArr[i] = arr[i];
            }

            newArr[index] = value;

            // put elements after insert into array
            for (size_t i = index; i < size; i++) {
                newArr[i + 1] = arr[i];
            }

            delete[] arr;
            arr = newArr;
        }
        else {
            // move elements to right of insert index
            for (size_t i = size; i > index; --i) {
                arr[i] = arr[i - 1];
            }

            arr[index] = value;
            size++;
        }
    }

    void popBack() {
        if (size > 0) {
            size--;
        }
    }

    void erase(size_t index) {
        // create new array with elements before index
        int* newArr = new T[capacity];
        for (size_t i = 0; i < index; i++) {
            newArr[i] = arr[i];
        }

        // put elements into erased index
        for (size_t i = index; i < size; i++) {
            newArr[i] = arr[i - 1];
        }

        delete[] arr;
        arr = newArr;

        size--;
    }
};


int main()
{
    MyVector<int> vec; 

    vec.pushBack(2);
    vec.pushBack(3);
    vec.pushBack(4);
    vec.insert(3, 5);
    vec.erase(3);

    for (int i = 0; i < vec.getSize(); i++) {
        std::cout << vec[i] << std::endl;
    }

}
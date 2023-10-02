#include<iostream>
using namespace std;
const int MAX_SIZE = 100;

class Array {
private:
    int arr[MAX_SIZE];
    int size;

public:
    Array() : size(0) {}

    void display() {
        std::cout << "Array elements: ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    void insertAtStart(int value) {
        if (size < MAX_SIZE) {
            for (int i = size; i > 0; --i) {
                arr[i] = arr[i - 1];
            }
            arr[0] = value;
            ++size;
        }
    }

    void insertAtEnd(int value) {
        if (size < MAX_SIZE) {
            arr[size] = value;
            ++size;
        }
    }

    void insertAtPosition(int value, int position) {
        if (position >= 0 && position <= size && size < MAX_SIZE) {
            for (int i = size; i > position; --i) {
                arr[i] = arr[i - 1];
            }
            arr[position] = value;
            ++size;
        }
    }

    void deleteAtStart() {
        if (size > 0) {
            for (int i = 0; i < size - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            --size;
        }
    }

    void deleteAtEnd() {
        if (size > 0) {
            --size;
        }
    }

    void deleteAtPosition(int position) {
        if (position >= 0 && position < size) {
            for (int i = position; i < size - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            --size;
        }
    }
};

int main() {
    Array arr;

    arr.insertAtStart(4);
    arr.insertAtEnd(6);
    arr.insertAtPosition(9,8);

    arr.display();

    arr.deleteAtStart();
    arr.deleteAtEnd();
    arr.deleteAtPosition(4);

    arr.display();

    return 0;
}
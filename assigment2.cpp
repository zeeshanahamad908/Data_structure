#include<iostream>
using namespace std;
#include <iostream>

void insertAtBeginning(int arr[], int& size, int value) {
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
}

void insertAtEnd(int arr[], int& size, int value) {
    arr[size] = value;
    size++;
}

void insertAtPosition(int arr[], int& size, int value, int position) {
    if (position < 0 || position > size) {
        std::cout << "Invalid position!" << std::endl;
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    size++;
}

void deleteFromBeginning(int arr[], int& size) {
    if (size <= 0) {
        std::cout << "Array is empty!" << std::endl;
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void deleteFromEnd(int arr[], int& size) {
    if (size <= 0) {
        std::cout << "Array is empty!" << std::endl;
        return;
    }

    size--;
}

void deleteFromPosition(int arr[], int& size, int position) {
    if (position < 0 || position >= size) {
        std::cout << "Invalid position!" << std::endl;
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size = 0;

    int choice;
    do {
        std::cout << "Current Array: ";
        displayArray(arr, size);

        std::cout << "Menu:" << std::endl;
        std::cout << "1. Insert at Beginning" << std::endl;
        std::cout << "2. Insert at End" << std::endl;
        std::cout << "3. Insert at Specific Position" << std::endl;
        std::cout << "4. Delete from Beginning" << std::endl;
        std::cout << "5. Delete from End" << std::endl;
        std::cout << "6. Delete from Specific Position" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int insertValue;
                std::cout << "Enter value to insert: ";
                std::cin >> insertValue;
                insertAtBeginning(arr, size, insertValue);
                break;
            case 2:
                std::cout << "Enter value to insert: ";
                std::cin >> insertValue;
                insertAtEnd(arr, size, insertValue);
                break;
            case 3:
                int insertPosition;
                std::cout << "Enter position to insert: ";
                std::cin >> insertPosition;
                std::cout << "Enter value to insert: ";
                std::cin >> insertValue;
                insertAtPosition(arr, size, insertValue, insertPosition);
                break;
            case 4:
                deleteFromBeginning(arr, size);
                break;
            case 5:
                deleteFromEnd(arr, size);
                break;
            case 6:
                int deletePosition;
                std::cout << "Enter position to delete: ";
                std::cin >> deletePosition;
                deleteFromPosition(arr, size, deletePosition);
                break;
            case 7:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 7);

    return 0;
}

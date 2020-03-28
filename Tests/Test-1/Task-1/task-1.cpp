#include <iostream>

void descCountingSort(int* arr, long long size) {
    // find max element
    int maxNumber = 0;
    for (long long i = 0; i < size; i++) {
        if (arr[i] > maxNumber) {
            maxNumber = arr[i];
        }
    }

    // allocate memory for a counting array
    int* countingArray = new int[maxNumber + 1];

    // initialise with zeroes
    for (int i = 0; i <= maxNumber; i++) {
        countingArray[i] = 0;
    }

    // fill counting array
    for (long long i = 0; i < size; i++) {
        countingArray[arr[i]]++;
    }

    long long sortingIndex = 0;
    // restore original array in descending order
    for (int i = maxNumber; i >= 0; i--) {
        while (countingArray[i] > 0) {
            arr[sortingIndex] = i;
            sortingIndex++;
            countingArray[i]--;
        }
    }

    delete[] countingArray;
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int size;
    std::cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    descCountingSort(arr, size);

    printArray(arr, size);

    delete[] arr;
    return 0;
}

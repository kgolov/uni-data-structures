#include <iostream>
#include <vector>

using std::vector;

vector<int> countingSort(vector<int> arr) {
    int size = arr.size();

    // Find max element
    int maxElement = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    // Allocate counting array
    int* countingArray = new int[maxElement + 1];

    // Initalise with zeroes
    for (int i = 0; i <= maxElement; i++) {
        countingArray[i] = 0;
    }

    // Fill counting array, only if the current total is zero
    // This removes duplicates
    for (int i = 0; i < size; i++) {
        if (countingArray[arr[i]] == 0) {
            countingArray[arr[i]] = 1;
        }
    }

    // Restore from counting array
    vector<int> sorted;
    for (int i = 0; i <= maxElement; i++) {
        if (countingArray[i] != 0) {
            sorted.push_back(i);
        }
    }

    return sorted;
}

int main() {
    int n;
    std::cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        arr.push_back(input);
    }

    vector<int> sortedArr = countingSort(arr);
    int newLength = sortedArr.size();

    for (int i = 0; i < newLength; i++) {
        std::cout << sortedArr[i] << " ";
    }

    return 0;
}

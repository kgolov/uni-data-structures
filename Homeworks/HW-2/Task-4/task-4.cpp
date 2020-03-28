#include <iostream>

// Merges two sorted arrays
// Returns: the number of inversions
// Long long is required to avoid overflow
long long merge(int* arr, int from, int middle, int to) {
    int tempSize = to - from + 1;
    int* temp = new int[tempSize];

    long long inversionCount = 0;

    int firstIndex = from;
    int secondIndex = middle;
    int tempIndex = 0;
    while (firstIndex <= middle - 1 && secondIndex <= to) {
        if (arr[firstIndex] <= arr[secondIndex]) {
            temp[tempIndex++] = arr[firstIndex++];
        }
        else {
            temp[tempIndex++] = arr[secondIndex++];

            inversionCount += ((long long)middle - firstIndex);
        }
    }
    while (firstIndex <= middle - 1) {
        temp[tempIndex++] = arr[firstIndex++];
    }
    while (secondIndex <= to) {
        temp[tempIndex++] = arr[secondIndex++];
    }

    for (int i = from; i <= to; i++) {
        arr[i] = temp[i - from];
    }

    delete[] temp;
    return inversionCount;
}

// Recursive merge sort implementation which returns the number of inversions in the original array
// Long long is required to avoid overflow
long long mergeSort(int* arr, int from, int to) {
    if (to <= from) { // bottom of recursion
        return 0;
    }

    long long inversionCount = 0;
    int middle = (from + to) / 2;

    inversionCount += mergeSort(arr, from, middle);
    inversionCount += mergeSort(arr, middle + 1, to);
    inversionCount += merge(arr, from, middle + 1, to);

    return inversionCount;
}

int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // The answer we are looking for is the number of inversions in the array
    // Find it using our altered merge sort algorithm
    long long ans = mergeSort(arr, 0, n - 1);
    std::cout << ans;

    delete[] arr;
    return 0;
}

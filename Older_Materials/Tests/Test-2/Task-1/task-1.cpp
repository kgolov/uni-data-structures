#include <iostream>

void merge(int* arr, int from, int middle, int to) {
    int tempSize = to - from + 1;
    int* temp = new int[tempSize];

    int firstIndex = from;
    int secondIndex = middle + 1;
    int tempIndex = 0;

    while (firstIndex <= middle && secondIndex <= to) {
        if (arr[firstIndex] < arr[secondIndex]) {
            temp[tempIndex] = arr[firstIndex];
            firstIndex++;
        }
        else {
            temp[tempIndex] = arr[secondIndex];
            secondIndex++;
        }
        tempIndex++;
    }
    while (firstIndex <= middle) {
        temp[tempIndex] = arr[firstIndex];
        firstIndex++;
        tempIndex++;
    }
    while (secondIndex <= to) {
        temp[tempIndex] = arr[secondIndex];
        secondIndex++;
        tempIndex++;
    }

    for (int i = from; i <= to; i++) {
        arr[i] = temp[i - from];
    }

    delete[] temp;
}

void mergeSort(int* arr, int from, int to) {
    if (to <= from) {
        std::cout << arr[from] << " ";
        return;
    }

    int middle = from + (to - from) / 2;
    mergeSort(arr, from, middle);
    mergeSort(arr, middle + 1, to);
    merge(arr, from, middle, to);

    for (int i = from; i <= to; i++) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int n;
    std::cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    delete[] arr;
    return 0;
}

#include <iostream>

// Using binary search, find the index of the next greater element than a given one
int getGreater(long long* arr, int size, long long element) {
    int leftBound = 0;
    int rightBound = size - 1;

    // Stores the index of the left most element
    // from the array which is greater than element
    int leftGreater = size;

    // Finds the required index
    while (leftBound <= rightBound) {
        int middle = leftBound + (rightBound - leftBound) / 2;

        // If the middle element is greater than
        // element update leftGreater and rightBound
        if (arr[middle] >= element) {
            leftGreater = middle;
            rightBound = middle - 1;
        }

        // If the middle element is less than
        // or equal to element update leftBound
        else {
            leftBound = middle + 1;
        }
    }

    // Return the index of the first element greater than element in the array
    return leftGreater;
}

// Find where the delicious strawberries are
void strawberries(long long* berries, int bowls, long long* deliciousPositions, int delicious) {
    // Allocate a new array in which we will sum the number of strawberries from the previous bowls
    long long* total = new long long[bowls];

    total[0] = berries[0];
    for (int i = 1; i < bowls; i++) {
        total[i] = berries[i] + total[i - 1];
    }

    // For each given # of delicious strawberry, find it and print where it is
    for (int i = 0; i < delicious; i++) {
        int position = getGreater(total, bowls, deliciousPositions[i]) + 1;
        std::cout << position << std::endl;
    }

    delete[] total;
}

int main() {
    int bowls;
    std::cin >> bowls;

    long long* berries = new long long[bowls];

    for (int i = 0; i < bowls; i++) {
        std::cin >> berries[i];
    }

    int delicious;
    std::cin >> delicious;

    long long* deliciousPositions = new long long[delicious];

    for (int i = 0; i < delicious; i++) {
        std::cin >> deliciousPositions[i];
    }

    strawberries(berries, bowls, deliciousPositions, delicious);

    delete[] berries;
    delete[] deliciousPositions;
    return 0;
}

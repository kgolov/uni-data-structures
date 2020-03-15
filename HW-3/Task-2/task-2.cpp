#include <iostream>
#include <algorithm>

// Checks if it is possible to arrange "target" elements from arr[0...size-1]
// with the minimum distance between them being minDist
bool isPossible(long long minDist, long long* arr, int size, int target) {
    // Place the first element at arr[0] position
    long long position = arr[0];

    // A count of elements placed
    int elements = 1;

    // Try placing "target" elements with minimum
    // distance minDist
    for (int i = 1; i < size; i++) {
        if (arr[i] - position >= minDist) {
            // Place the next element if its distance from the previously placed
            // is greater than minDist
            position = arr[i];
            elements++;

            // Return if all elements are placed
            // successfully
            if (elements == target) {
                return true;
            }
        }
    }

    // Else, arrangement is not possible, so return false
    return false;
}

// Returns the largest minimum distance between two cows, placed in the houses
long long largestMinDist(long long* arr, int houses, int cows) {
    // Sort the positions of the houses
    std::sort(arr, arr + houses);

    // Initialize a variable for the result
    long long result = -1;

    // Consider the maximum possible distance
    long long left = arr[0];
    long long right = arr[houses - 1];

    // Do a binary search for the largest minimum distance
    while (left <= right) {
        long long middle = (left + right) / 2;

        // If it is possible to place the cows with minimum distance middle,
        // search for a higher distance
        if (isPossible(middle, arr, houses, cows)) {
            // Change the value of the result variable
            // if all the cows can be successfully placed
            if (middle > result) {
                result = middle;
            }
            // Continue searching for a higher distance
            left = middle + 1;
        }
        // If it is not possible to place the cows within this minimum distance,
        // search for a lower one
        else {
            right = middle - 1;
        }
    }

    return result;
}

int main() {
    int houses;
    std::cin >> houses;
    int cows;
    std::cin >> cows;

    long long* positions = new long long[houses];

    for (int i = 0; i < houses; i++) {
        std::cin >> positions[i];
    }

    std::cout << largestMinDist(positions, houses, cows);

    delete[] positions;
    return 0;
}

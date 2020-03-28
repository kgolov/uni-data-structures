#include <iostream>

// Calculates the number of balloons needed if the maximum number of sweets is target
long long balloonsNeeded(long long* sweets, long long* maxSweets, int size, long long target) {
    long long counter = 0;

    for (int i = 0; i < size; i++) {
        // Check if we need balloons here to reduce the maximum number of sweets
        if (maxSweets[i] > target) {
            long long difference = maxSweets[i] - target;

            // The balloons needed to make up this difference are the difference divided by the sweets
            // field of the current day, rounded up to an integer
            long long balloons = 1 + ((difference - 1) / sweets[i]);

            counter += balloons;
        }
    }

    return counter;
}

// Finds the minimum number of max sweets needed
long long findMaxSweets(long long* sweets, long long* maxSweets, int size, long long balloons) {
    // Conduct a binary search for the answer
    // The maximum number of sweets is our upper bound
    long long left = 0;
    long long right = 0;
    for (int i = 0; i < size; i++) {
        if (maxSweets[i] > right) {
            right = maxSweets[i];
        }
    }

    // We will store our result here
    long long result = right;

    while (left <= right) {
        // Take a guess for the maximum number of sweets, in the middle between our lower and upper bounds
        long long middle = left + (right - left) / 2;

        // If the balloons needed for this given number of sweets are lower than, or equal to the amount we have
        if (balloonsNeeded(sweets, maxSweets, size, middle) <= balloons) {
            // Then, this is a possible solution, so save it as a result
            if (middle < result) {
                result = middle;
            }
            // And update our upper bound to search for an even lower possible number
            right = middle - 1;
        }
        else {
            // Else, this cannot be a solution, so search for a higher number
            left = middle + 1;
        }
    }

    // We have found the minimum number of max sweets
    return result;
}

int main() {
    int days;
    std::cin >> days;

    long long balloons;
    std::cin >> balloons;

    long long* maxBalloons = new long long[days];
    long long* sweets = new long long[days];
    long long* maxSweets = new long long[days];

    for (int i = 0; i < days; i++) {
        std::cin >> maxBalloons[i];
    }
    for (int i = 0; i < days; i++) {
        std::cin >> sweets[i];
        maxSweets[i] = maxBalloons[i] * sweets[i];
    }

    std::cout << findMaxSweets(sweets, maxSweets, days, balloons);
    return 0;
}

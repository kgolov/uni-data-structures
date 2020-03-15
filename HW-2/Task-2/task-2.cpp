#include <iostream>

// Counting Sort implementation, which removes duplicate elements
// and replaces them with zeroes
// RETURNS: how many duplicates it has found
// For example: 5 2 3 5 becomes 0 2 3 5
int countingSort(int* arr, int size) {
    // First, find the maximum number of the array
    int maxNumber = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > maxNumber) {
            maxNumber = arr[i];
        }
    }

    // Allocate memory for a new counting array
    int* countingArray = new int[maxNumber + 1];
    for (int i = 0; i < maxNumber + 1; i++) {
        countingArray[i] = 0;
    }

    // Fill the counting array
    for (int i = 0; i < size; i++) {
        countingArray[arr[i]]++;
    }

    // Remove duplicates, leaving only one unique element
    // Add zeroes where needed
    int duplicates = 0;
    for (int i = 1; i <= maxNumber; i++) {
        while (countingArray[i] > 1) {
            countingArray[i]--;
            countingArray[0]++;
            duplicates++;
        }
    }

    // Restore the sorted array
    int sortedIndex = 0;
    for (int i = 0; i < size; i++) {
        while (countingArray[sortedIndex] == 0) {
            sortedIndex++;
        }

        arr[i] = sortedIndex;
        countingArray[sortedIndex]--;
    }

    delete[] countingArray;

    // Return the number of duplicates
    return duplicates;
}

// The main function, which calculates the minimum number of shots with the blaster
int monstersCalculation(int* monsters, int size, int power) {
    // Firstly, sort the input array with counting sort, while removing duplicates
    long long duplicates = countingSort(monsters, size);

    long long killedByBlasting = 0;
    long long killedByFalling = 0;

    // NOTE: long long variables are needed, because when we sum them, we may overflow the int
    // If their sum is smaller than the total number of monsters, this means we still have some alive
    while (duplicates + killedByFalling + killedByBlasting < size) {
        // We start working on the array from where it becomes positive - i.e. from the number of killed by falling
        // (zeroes) monsters + the number of duplicates from the beginning
        int firstPositive = killedByFalling + duplicates;

        // Let us kill the last monster in the array, which is not already blasted
        int indexToKill = size - killedByBlasting - 1;

        // Kill the monster and increment the number of kills
        monsters[indexToKill] = 0;
        killedByBlasting++;

        // Move all monsters left of the killed one as required
        for (int i = firstPositive; i < indexToKill; i++) {
            monsters[i] -= power;
            // If a monster falls out, record it
            if (monsters[i] <= 0) {
                monsters[i] = 0;
                killedByFalling++;
            }
        }
    }

    // We have now found the minimum number of kills
    return killedByBlasting;
}

int main() {
    int size;
    std::cin >> size;
    int power;
    std::cin >> power;

    int* monsters = new int[size];

    for (int i = 0; i < size; i++) {
        std::cin >> monsters[i];
    }

    // Output on the console the calculations which we make
    std::cout << monstersCalculation(monsters, size, power);

    delete[] monsters;
    return 0;
}

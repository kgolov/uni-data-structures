#include <iostream>
#include <vector>

using std::vector;

// Function which calculates if you can go out with a single throw
int canGoOut(int pts) {
    if (pts < 2 || pts > 50) {
        // There is no way if the points are less than 2 or more than 50
        return 0;
    }

    // List which contains all possible 1-dart finishes
    const int ALL_OUTS = 21;
    const int possibleOuts[ALL_OUTS] = {  2,  4,  6,  8, 10, 12, 14, 16, 18, 20,
                                         22, 24, 26, 28, 30, 32, 34, 36, 38, 40,
                                         50 };

    int possibilities = 0;

    // We check if the required points are in our list
    for (int i = 0; i < ALL_OUTS; i++) {
        if (pts == possibleOuts[i]) {
            possibilities++;
        }
    }

    return possibilities;
}

// Function which calculates the number of possible ways to go out, including 1-dart, 2-dart and 3-dart finishes
int darts(int pts) {
    // List of all possible throws with one dart
    const int ALL_THROWS = 63;
    const int possibleThrows[ALL_THROWS] = {
        1, 2, 3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        2, 4, 6,  8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40,
        3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 60,
        25, 50, 0 };

    // Starting a counter for the number of combinations
    int combinations = 0;

    int ptsLeft = pts;

    // Try one-dart finish
    combinations += canGoOut(pts);

    // Try two-dart finishes
    for (int i = 0; i < ALL_THROWS; i++) {
        // Try every possible throw with the first dart, and then check the remaining points to see if you can go out
        ptsLeft -= possibleThrows[i];
        combinations += canGoOut(ptsLeft);
        ptsLeft = pts;
    }

    // Try three-dart finishes
    for (int i = 0; i < ALL_THROWS; i++) {
        // Try every possible throw with the first and second dart, then check
        // the remaining points to see if you can go out
        ptsLeft -= possibleThrows[i];
        for (int j = 0; j < ALL_THROWS; j++) {
            combinations += canGoOut(ptsLeft - possibleThrows[j]);
        }
        ptsLeft = pts;
    }

    // We have calculated the number of possibilities for a finish
    return combinations;
}

int main() {
    int input;
    std::cin >> input;

    std::cout << darts(input);

    return 0;
}

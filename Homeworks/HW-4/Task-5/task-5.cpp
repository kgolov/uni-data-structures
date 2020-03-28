// SDA 2019-2020, HW 4, task 5
// https://www.hackerrank.com/contests/practice-4-sda/challenges/truck-ordering

#include <iostream>
#include <stack>

using std::stack;

bool canRearrange(int* order, int trucks) {
    stack<int> sideStreet;

    int index = 0;
    int previousPassed = 0;

    while (index < trucks) {
        if (order[index] - 1 == previousPassed) {
            previousPassed = order[index];
        }
        else {
            sideStreet.push(order[index]);
        }
        index++;
    }

    // Try to replace them back
    while (!sideStreet.empty()) {
        // The first tries to go out
        if (sideStreet.top() == previousPassed + 1) {
            // It can go out, the order is fine
            previousPassed = sideStreet.top();
            sideStreet.pop();
        }
        else {
            // Else, the arrangement breaks
            return false;
        }
    }

    return true;
}


int main() {
    int repeat;
    std::cin >> repeat;

    bool* output = new bool[repeat];

    for (int i = 0; i < repeat; i++) {
        int trucks;
        std::cin >> trucks;
        int* order = new int[trucks];

        for (int j = 0; j < trucks; j++) {
            std::cin >> order[j];
        }

        output[i] = canRearrange(order, trucks);

        delete[] order;
    }

    for (int i = 0; i < repeat; i++) {
        if (output[i]) {
            std::cout << "yes" << std::endl;
        }
        else {
            std::cout << "no" << std::endl;
        }
    }

    delete[] output;
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using std::priority_queue;
using std::vector;

int main() {
    // Magic lines
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int number;
    std::cin >> number;
    int input;
    int inputSecond;

    double* output = new double[number];

    priority_queue<int, vector<int>, std::less<int>> lower; //maxHeap for lower values
    priority_queue<int, vector<int>, std::greater<int>> higher; //minHeap for higher values

    // Add first two numbers
    std::cin >> input;
    output[0] = input;

    std::cin >> inputSecond;
    output[1] = (((double)input + inputSecond) / 2.0);

    if (input < inputSecond) {
        lower.push(input);
        higher.push(inputSecond);
    }
    else {
        lower.push(inputSecond);
        higher.push(input);
    }

    // Start pushing number into queues
    for (int i = 2; i < number; i++) {
        std::cin >> input;
        if (input > lower.top()) {
            higher.push(input);
        }
        else {
            lower.push(input);
        }

        // Balance queues if needed
        if (lower.size() > higher.size() + 1) {
            int toMove = lower.top();
            lower.pop();
            higher.push(toMove);
        }
        else if (higher.size() > lower.size() + 1) {
            int toMove = higher.top();
            higher.pop();
            lower.push(toMove);
        }

        // Calculate medians
        if (lower.size() == higher.size()) {
           output[i] = (((double)lower.top() + higher.top()) / 2.0);
        }
        else if (lower.size() > higher.size()) {
            output[i] = lower.top();
        }
        else {
            output[i] = higher.top();
        }
    }

    // Print medians using printf (seems faster)
    for (int i = 0; i < number; i++) {
        printf("%.1f\n", output[i]);
    }

    delete[] output;
    return 0;
}

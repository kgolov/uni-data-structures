#include <iostream>
#include <stack>

using std::stack;

int pickPosition(stack<int> trees, int num) {
    stack<int> seeableTrees;

    int currentPosition = num - 1;
    int counter = 0;

    int maxCounter = 0;
    int maxPosition = num - 1;

    while (!trees.empty()) {
        while (!seeableTrees.empty() && trees.top() >= seeableTrees.top()) {
            seeableTrees.pop();
            counter--;
        }

        seeableTrees.push(trees.top());
        counter++;
        if (counter >= maxCounter) {
            maxCounter = counter;
            maxPosition = currentPosition;
        }
        trees.pop();

        currentPosition--;
    }

    return maxPosition;
}

int main() {
    int num;
    std::cin >> num;

    stack<int> trees;

    for (int i = 0; i < num; i++) {
        int input;
        std::cin >> input;
        trees.push(input);
    }

    std::cout << pickPosition(trees, num);

    return 0;
}

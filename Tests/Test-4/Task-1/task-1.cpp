#include <iostream>
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

void commandos() {
    priority_queue<long long, vector<long long>, std::greater<long long>> q;

    long long n;
    std::cin >> n;
    long long input;

    for (long long i = 0; i < n; i++) {
        std::cin >> input;

        if (input >= 0) {
            q.push(input);
        }
        else if (input == -1) {
            if (!q.empty()) {
                std::cout << q.top() << " ";
                q.pop();
            }
        }
    }
}

int main() {
    commandos();

    return 0;
}

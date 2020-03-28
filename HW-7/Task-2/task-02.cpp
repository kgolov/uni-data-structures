#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // Magic lines
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int rooms;
    std::cin >> rooms;
    int inputKey;
    int result = 0;

    int* keysInRooms = new int[rooms - 1];
    unordered_map<int, int> currentKeys;

    for (int i = 0; i < rooms - 1; i++) {
        std::cin >> inputKey;
        keysInRooms[i] = inputKey;
    }

    for (int i = 0; i < rooms - 1; i++) {
        currentKeys[keysInRooms[i]]++;

        std::cin >> inputKey;

        auto it = currentKeys.find(inputKey);
        if (it != currentKeys.end() && it->second != 0) {
            it->second--;
        }
        else {
            result++;
        }
    }

    std::cout << result;
    return 0;
}

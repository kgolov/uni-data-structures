#include <iostream>
#include <vector>

using std::vector;

int water(vector<int> walls) {
    int maxVol = 0;
    int wallsN = walls.size();

    for (int i = 0; i < wallsN - 1; i++) {
        for (int j = i + 1; j < wallsN; j++) {
            // Find smaller wall
            int smaller;
            if (walls[i] < walls[j]) {
                smaller = walls[i];
            }
            else {
                smaller = walls[j];
            }

            // Find volume
            int volume = smaller * (j - i);

            if (volume > maxVol) {
                maxVol = volume;
            }
        }
    }

    return maxVol;
}

int main() {
    int n;
    std::cin >> n;

    vector<int> walls;

    for (int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        walls.push_back(input);
    }

    std::cout << water(walls);

    return 0;
}

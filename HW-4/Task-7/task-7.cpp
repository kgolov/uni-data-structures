#include <iostream>

void chooseTeams(int* arr, int number, int* positions, int choose) {
    int* teams = new int[number];
    for (int i = 0; i < number; i++) {
        teams[i] = 0;
    }

    int nextTeam = 1;

    for (int i = number; i >= 1; i--) {
        // We grab each number's index from positions
        // Starting from the biggest ones
        if (teams[positions[i]] == 0) {
            // We choose its team, as it hasn't got one
            teams[positions[i]] = nextTeam;

            // We choose right and left of it
            int chosen = 0;
            for (int j = positions[i] + 1; j < number; j++) {
                if (chosen >= choose) {
                    break;
                }

                if (teams[j] == 0) {
                    chosen++;
                    teams[j] = nextTeam;
                }
            }
            chosen = 0;
            for (int j = positions[i] - 1; j >= 0; j--) {
                if (chosen >= choose) {
                    break;
                }

                if (teams[j] == 0) {
                    chosen++;
                    teams[j] = nextTeam;
                }
            }

            // We swap teams
            if (nextTeam == 1) nextTeam = 2;
            else nextTeam = 1;
        }
    }

    for (int i = 0; i < number; i++) {
        std::cout << teams[i];
    }

    delete[] teams;
}

int main() {
    // How many numbers will be entered
    int number;
    std::cin >> number;
    // How many numbers on each side we will choose
    int choose;
    std::cin >> choose;

    // Array to store the numbers
    int* arr = new int[number];
    // Array to store where each number is located
    // (We know the numbers are going to be permutations of 1 to number)
    int* positions = new int[number + 1];

    for (int i = 0; i < number; i++) {
        std::cin >> arr[i];
        positions[arr[i]] = i;
    }

    chooseTeams(arr, number, positions, choose);

    delete[] arr;
    delete[] positions;
    return 0;
}

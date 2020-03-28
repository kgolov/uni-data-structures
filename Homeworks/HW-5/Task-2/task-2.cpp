#include <iostream>
#include <queue>

using std::queue;

int ROWS = 0;
int COLS = 0;

struct Apple {
    int x;
    int y;
    int level = 0;

    Apple(int x, int y, int level) {
        this->x = x;
        this->y = y;
        this->level = level;
    }
};

// Here x is between 0 and ROWS - 1
// y is between 0 and COLS - 1 (we use indexation from 0)
bool isValid(int x, int y, bool** rotten) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return false;
    }

    if (rotten[x][y]) {
        return false;
    }

    else return true;
}

int main() {
    std::cin >> ROWS;
    std::cin >> COLS;

    int days;
    std::cin >> days;

    bool** rotten = new bool* [ROWS];
    for (int i = 0; i < ROWS; i++) {
        rotten[i] = new bool[COLS];
        for (int j = 0; j < COLS; j++) {
            rotten[i][j] = false;
        }
    }

    queue<Apple*> q;
    int counter = 0;

    int x; int y;
    while (std::cin >> x >> y) {
        // Set the apple at this position as rotten on level 0
        // However, the indexation is different
        // Calculate new indexes in the matrix
        rotten[ROWS - x][y - 1] = true;
        // Add to queue as a start point
        Apple* toAdd = new Apple(ROWS - x, y - 1, 0);
        q.push(toAdd);
        counter++;
    }

    while (!q.empty()) {
        Apple* current = q.front();
        // If we have reached the number of days, stop the cycle
        if (current->level >= days) {
            break;
        }

        // Try right
        int newX = current->x;
        int newY = current->y + 1;
        int newLevel = current->level + 1;
        if (isValid(newX, newY, rotten)) {
            Apple* next = new Apple(newX, newY, newLevel);
            rotten[newX][newY] = true;
            q.push(next);
            counter++;
        }

        // Try left
        newY = current->y - 1;
        if (isValid(newX, newY, rotten)) {
            Apple* next = new Apple(newX, newY, newLevel);
            rotten[newX][newY] = true;
            q.push(next);
            counter++;
        }

        // Try up
        newY = current->y;
        newX = current->x - 1;
        if (isValid(newX, newY, rotten)) {
            Apple* next = new Apple(newX, newY, newLevel);
            rotten[newX][newY] = true;
            q.push(next);
            counter++;
        }

        // Try down
        newX = current->x + 1;
        if (isValid(newX, newY, rotten)) {
            Apple* next = new Apple(newX, newY, newLevel);
            rotten[newX][newY] = true;
            q.push(next);
            counter++;
        }

        // Free the memory and pop the last apple
        q.pop();
        delete current;
    }

    // Count the apples which are not rotten
    int result = ROWS * COLS - counter;

    // Free the remaining allocated memory
    while (!q.empty()) {
        Apple* toDelete = q.front();
        q.pop();
        delete toDelete;
    }

    // Print result
    std::cout << result;

    // Free the boolean matrix
    for (int i = 0; i < ROWS; i++) {
        delete[] rotten[i];
    }
    delete[] rotten;

    return 0;
}

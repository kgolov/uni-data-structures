#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

const pii INVALID = make_pair(-1, -1);

enum Direction {
    UP, DOWN, LEFT, RIGHT
};

pii movePoint(pii point, Direction dir) {
    pii next;

    if (dir == UP) {
        next = { point.first - 1, point.second };
    }
    else if (dir == DOWN) {
        next = { point.first + 1, point.second };
    }
    else if (dir == LEFT) {
        next = { point.first, point.second - 1 };
    }
    else if (dir == RIGHT) {
        next = { point.first, point.second + 1 };
    }

    return next;
}

bool isValid(pii point, vector<vector<char>>& lb) {
    if (lb[point.first][point.second] == '.' ||
        lb[point.first][point.second] == 'S' || lb[point.first][point.second] == 'F') {
        return true;
    }
    return false;
}

bool isValidNext(pii point, Direction dir, vector<vector<char>>& lb) {
    pii next = movePoint(point, dir);

    if (dir == UP && next.first < 0) {
        return false;
    }
    else if (dir == DOWN && next.first >= lb.size()) {
        return false;
    }
    else if (dir == LEFT && next.second < 0) {
        return false;
    }
    else if (dir == RIGHT && next.second >= lb[next.first].size()) {
        return false;
    }

    if (isValid(next, lb)) {
        return true;
    }
    return false;
}

pii findPortal(pii point, Direction dir, vector<vector<char>>& lb) {
    pii current = point;

    while (isValidNext(current, dir, lb)) {
        current = movePoint(current, dir);
    }

    if (current == point) {
        return INVALID;
    }
    return current;
}

int main() {
    int rows, cols;
    std::cin >> rows >> cols;
    vector<vector<char>> lb(rows);

    int validPoints = 0;
    pii start, finish, current;

    int key = 0;
    map<pii, int> keys;

    // Entering of the labyrinth
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            char c;
            std::cin >> c;
            lb[row].push_back(c);

            current = make_pair(row, col);

            // Count if it is a valid point, to have the resulting number of points
            if (c == '.' || c == 'S' || c == 'F') {
                validPoints++;

                // Also make the preindexation for the graph later
                keys.insert({ current, key++ });
            }

            // Also record where start and finish points are
            if (c == 'S') {
                start = current;
            }
            else if (c == 'F') {
                finish = current;
            }
        }
        std::cin.ignore();
    }

    // Build a graph from the labyrinth
    vector<vector<int>> graph(validPoints);

    pii next;
    int currentKey, nextKey;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            current = make_pair(row, col);
            if (!isValid(current, lb)) {
                continue;
            }
            currentKey = keys[current];

            // If the point above is valid, add a link in the graph
            if (isValidNext(current, UP, lb)) {
                next = movePoint(current, UP);
                nextKey = keys[next];

                graph[currentKey].push_back(nextKey);
            }
            if (isValidNext(current, DOWN, lb)) {
                next = movePoint(current, DOWN);
                nextKey = keys[next];

                graph[currentKey].push_back(nextKey);
            }
            if (isValidNext(current, LEFT, lb)) {
                next = movePoint(current, LEFT);
                nextKey = keys[next];

                graph[currentKey].push_back(nextKey);
            }
            if (isValidNext(current, RIGHT, lb)) {
                next = movePoint(current, RIGHT);
                nextKey = keys[next];

                graph[currentKey].push_back(nextKey);
            }

            // Now check possible portals each way and add a link to the graph
            next = findPortal(current, UP, lb);
            if (next != INVALID) {
                nextKey = keys[next];

                graph[currentKey].push_back(nextKey);
            }

            next = findPortal(current, DOWN, lb);
            if (next != INVALID) {
                nextKey = keys[next];

                graph[currentKey].push_back(nextKey);
            }

            next = findPortal(current, LEFT, lb);
            if (next != INVALID) {
                nextKey = keys[next];

                graph[currentKey].push_back(nextKey);
            }

            next = findPortal(current, RIGHT, lb);
            if (next != INVALID) {
                nextKey = keys[next];

                graph[currentKey].push_back(nextKey);
            }
        }
    }

    // Finally, graph should be built, so now we must find the minimum distance
    // between start and finish points using BFS
    int startKey = keys[start];
    int finishKey = keys[finish];

    vector<bool> visited;
    visited.assign(validPoints, false);
    vector<int> distances;
    distances.assign(validPoints, -1);

    queue<int> q;
    q.push(startKey);
    visited[startKey] = true;
    distances[startKey] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                distances[next] = distances[curr] + 1;
            }
        }
    }

    std::cout << distances[finishKey];

    return 0;
}

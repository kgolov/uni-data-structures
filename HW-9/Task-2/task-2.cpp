#include <bits/stdc++.h>

using std::priority_queue;
using std::vector;
using std::map;
using std::pair;

void dijkstra(int start, vector<map<int, int>>& graph, vector<int>& distances) {
    int n = graph.size();

    distances.assign(n, -1);
    distances[start] = 0;

    vector<bool> visited;
    visited.assign(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
    pq.push({ distances[start], start });
    while(!pq.empty()) {
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        if (visited[currNode]) {
            continue;
        }
        visited[currNode] = true;

        for (auto next : graph[currNode]) {
            int nextNode = next.first;
            int nextDist = next.second;

            int alternativeDist = currDist + nextDist;
            if (distances[nextNode] < 0 || alternativeDist < distances[nextNode]) {
                distances[nextNode] = alternativeDist;
                pq.push({ distances[nextNode], nextNode });
            }
        }
    }
}

void findDistances(vector<map<int, int>>& graph, vector<vector<int>>& matrix) {
    int n = graph.size();
    matrix.reserve(n);
    for (int i = 0; i < n; i++) {
        matrix[i].assign(n, -1);
    }

    vector<int> distances;
    for (int i = 0; i < n; i++) {
        dijkstra(i, graph, distances);

        for (int j = 0; j < n; j++) {
            matrix[i][j] = distances[j];
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    vector<map<int, int>> graph(n);
    int x, y, c;

    for (int i = 0; i < m; i++) {
        std::cin >> x >> y >> c;
        x--; y--;

        graph[x][y] = c;
    }

    int queries;
    std::cin >> queries;

    vector<vector<int>> matrix;

    findDistances(graph, matrix);

    for (int i = 0; i < queries; i++) {
        std::cin >> x >> y;
        x--; y--;

        std::cout << matrix[x][y] << '\n';
    }

    return 0;
}

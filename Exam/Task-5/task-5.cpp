#include <bits/stdc++.h>

using namespace std;

int findPath(int start, int finish, vector<vector<int>>& graph, vector<bool>& visited) {
    int n = graph.size();

    vector<int> distances(n);
    distances.assign(n, -1);
    visited[start] = true;
    distances[start] = 0;

    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int currNode = q.front();
        q.pop();

        for (int neighbor : graph[currNode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                distances[neighbor] = distances[currNode] + 1;
            }
        }
    }

    return distances[finish];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;

        graph[x].push_back(y);
    }

    int k;
    cin >> k;
    vector<int> path;
    int input;
    for (int i = 0; i < k; i++) {
        cin >> input;
        path.push_back(input);
    }

    int shortestPath = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        int firstNode = path[i];
        int secondNode = path[i+1];

        vector<bool> visited;
        visited.assign(n, false);

        for (int j = i+2; j < path.size(); j++) {
            visited[path[j]] = true;
        }

        int pathIsFound = findPath(firstNode, secondNode, graph, visited);
        if (pathIsFound == -1) {
            cout << -1;
            return 0;
        }
        shortestPath += pathIsFound;
    }

    cout << shortestPath;
    return 0;
}

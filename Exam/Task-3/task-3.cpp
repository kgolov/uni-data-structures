#include <bits/stdc++.h>

using namespace std;

int countComponents(vector<vector<int>>& graph, vector<int>& visited) {
    int n = graph.size();
    visited.assign(n, false);

    int components = 0;
    for(int i = 0; i < n; i++) {
        if (!visited[i]) {
            // Run BFS
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty()) {
                int currNode = q.front();
                q.pop();

                for (int neighbor : graph[currNode]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }

            components++;
        }
    }

    return components;
}

int main() {
    int tests;
    cin >> tests;

    for (int k = 0; k < tests; k++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n);
        int x, y;

        for (int i = 0; i < m; i++) {
            cin >> x >> y;

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<int> visited;
        cout << countComponents(graph, visited) << " ";
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

bool hasCycle(int currNode, vector<vector<pair<int, int>>>& graph, vector<int>& visited) {
    visited[currNode] = 1;

    for (auto el : graph[currNode]) {
        if (visited[el.first] == 1) {
            return true;
        }
        else if (visited[el.first] == 0) {
            if(hasCycle(el.first, graph, visited)) {
                return true;
            }
        }
    }

    visited[currNode] = 2;
    return false;
}

int main() {
    int n;
    cin >> n;

    for (int k = 0; k < n; k++) {
        int size, m;
        cin >> size >> m;
        vector<vector<pair<int, int>>> graph(size + 1);

        int x, y, z;
        for (int j = 0; j < m; j++) {
            cin >> x >> y >> z;

            graph[x].push_back({y, z});
        }

        vector<int> visited;
        visited.assign(size + 1, 0);

        bool flag = false;
        for (int i = 1; i <= size; i++) {
            if (visited[i] == 0) {
                if (hasCycle(i, graph, visited)) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag) {
            cout << "true ";
        }
        else {
            cout << "false ";
        }
    }

    return 0;
}

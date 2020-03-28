#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

void dfs(int node, vector<bool>& visited, vector<unordered_set<int>>& graph) {
    visited[node] = true;

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next, visited, graph);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int components = 0;

    unordered_map<int, int> keys;
    int key = 0;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        x -= 1;
        y -= 1;

        if (!keys.count(x)) {
            keys.insert({ x, key++ });
        }
        if (!keys.count(y)) {
            keys.insert({ y, key++ });
        }

        edges.push_back({ x, y });
    }

    components = n - keys.size();

    // Build smaller graph only from given edges(preindexed)
    vector<unordered_set<int>> graph(keys.size());
    for (auto edge : edges) {
        int first = keys[edge.first];
        int second = keys[edge.second];

        graph[first].insert(second);
        graph[second].insert(first);
    }

    vector<bool> visited;
    visited.assign(graph.size(), false);
    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) {
            dfs(i, visited, graph);
            components++;
        }
    }

    cout << components;

    return 0;
}

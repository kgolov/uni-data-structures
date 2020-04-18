#include <bits/stdc++.h>

using namespace std;

int pathCheck(vector<unordered_map<int, int>>& graph, vector<int>& path) {
    int n = graph.size();

    int pathLength = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        int firstNode = path[i];
        int secondNode = path[i+1];

        unordered_map<int, int>::iterator found = graph[firstNode].find(secondNode);
        if (found != graph[firstNode].end()) {
            pathLength += found->second;
        }
        else {
            return -1;
        }
    }

    return pathLength;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<unordered_map<int, int>> graph(n);
    int x, y, c;

    for (int i = 0; i < m; i++) {
        cin >> x >> y >> c;

        graph[x].insert({y, c});
        graph[y].insert({x, c});
    }

    int k;
    cin >> k;
    vector<int> pathToCheck;

    for (int i = 0; i < k; i++) {
        cin >> x;

        pathToCheck.push_back(x);
    }

    cout << pathCheck(graph, pathToCheck);

    return 0;
}

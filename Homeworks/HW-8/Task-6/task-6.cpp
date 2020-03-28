#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

// Recursively find the number of paths, while saving every node's children's number of paths
// So as to compute them only once
int compute(int current, int finish, vector<vector<int>>& graph, vector<int>& numOfPaths) {
    // If the current node is the finish node, there is only 1 path to itself
    if (current == finish) {
        numOfPaths[current] = 1;
        return 1;
    }

    // Else, the number of paths to the finish node are the sum of its children's paths to the finish node
    // If we have not computed, compute the paths now
    if (numOfPaths[current] == -1) {
        long long paths = 0;

        for (int child : graph[current]) {
            paths += compute(child, finish, graph, numOfPaths);
        }

        paths %= MOD;

        numOfPaths[current] = paths;
    }
    // Return the number of paths
    return numOfPaths[current];
}

int main() {
    // Magic lines
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    vector<vector<int>> graph(n);
    int x, y;
    for (int i = 0; i < m; i++) {
        std::cin >> x >> y;
        x--;
        y--;

        graph[x].push_back(y);
    }

    int start, end;
    std::cin >> start >> end;
    start--;
    end--;

    vector<int> numOfPaths;
    numOfPaths.assign(n, -1);

    int paths = compute(start, end, graph, numOfPaths);

    std::cout << paths;

    return 0;
}

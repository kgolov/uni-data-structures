#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>

using namespace std;

const int MAX_V = 100001;

vector<int> graph[MAX_V];
int visited[MAX_V] = {};
int parents[MAX_V];
int endOfCycle = -1;
int startNode;

void dfs(int node) {
    if (endOfCycle != -1) return;

    visited[node] = 1;

    for (int next : graph[node]) {
        if (visited[next] == 0) {
            parents[next] = node;
            dfs(next);
        }
        else if (next == startNode) {
            endOfCycle = node;
            return;
        }
    }

    visited[node] = 2;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> keys;
    unordered_map<int, string> cities;
    int currentKey = 0;

    string city1, city2;
    int key1, key2;
    for (int i = 0; i < m; i++) {
        cin >> city1 >> city2;

        if (keys.count(city1) == 0) {
            keys.insert({ city1, currentKey });
            cities.insert({ currentKey, city1 });
            currentKey++;
        }
        key1 = keys[city1];

        if (keys.count(city2) == 0) {
            keys.insert({ city2, currentKey });
            cities.insert({ currentKey, city2 });
            currentKey++;
        }
        key2 = keys[city2];

        graph[key1].push_back(key2);
    }

    // Input start city
    cin >> city1;
    startNode = keys[city1];

    dfs(startNode);

    if (endOfCycle == -1) {
        cout << "-1\n";
        return 0;
    }

    vector<int> path;
    for (int i = endOfCycle; i != startNode; i = parents[i]) {
        path.push_back(i);
    }
    path.push_back(startNode);

    std::reverse(path.begin(), path.end());
    path.push_back(startNode);

    for (int x : path) {
        std::cout << cities[x] << " ";
    }

    cout << "\n";

    return 0;
}

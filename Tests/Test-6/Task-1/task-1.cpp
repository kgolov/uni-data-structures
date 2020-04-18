#include <bits/stdc++.h>

using namespace std;

void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& distances) {
    int n = graph.size();

    distances.assign(n, -1);
    distances[start] = 0;

    vector<bool> visited;
    visited.assign(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ distances[start], start });
    while(!pq.empty()) {
        int currNode = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        if (visited[currNode]) {
            continue;
        }
        visited[currNode] = true;

        for (auto neigh : graph[currNode]) {
            int nextNode = neigh.first;
            int nextDist = neigh.second;

            int alternativeDist = currDist + nextDist;
            if (distances[nextNode] == -1 || alternativeDist < distances[nextNode]) {
                distances[nextNode] = alternativeDist;
                pq.push({ distances[nextNode], nextNode });
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int x, y, c;

    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++) {
        cin >> x >> y >> c;

        x--; y--;

        graph[x].push_back({ y, c });
        graph[y].push_back({ x, c });
    }

    int start;
    cin >> start;
    start--;

    vector<int> distances;
    dijkstra(start, graph, distances);

    distances.erase(distances.begin() + start);

    for (auto distance : distances) {
        cout << distance << " ";
    }

    cout << endl;

    return 0;
}

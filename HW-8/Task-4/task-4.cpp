#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>

using namespace std;
using pii = pair<int, int>;

const int INF = INT_MAX;

void dijkstra(int node, vector<int>& distances, vector<vector<pii>>& graph) {
    int n = graph.size();
    distances.assign(n, INF);
    vector<bool> visited;
    visited.assign(n, false);

    priority_queue<pii, vector<pii>, greater<pii>> q;
    distances[node] = 0;
    q.push({ 0, node });
    while (!q.empty()) {
        int currNode = q.top().second;
        int currDist = q.top().first;
        q.pop();

        if (visited[currNode]) {
            continue;
        }
        visited[currNode] = true;

        for (auto next : graph[currNode]) {
            int neighborNode = next.first;
            int neighborDist = next.second;

            int alternative = distances[currNode] + neighborDist;

            if (alternative < distances[neighborNode]) {
                distances[neighborNode] = alternative;
                q.push({ distances[neighborNode], neighborNode });
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    const int DUMMY = n;

    vector<vector<pii>> graph(n + 1);
    int x, y, c;
    for (int i = 0; i < m; i++) {
        std::cin >> x >> y >> c;
        graph[x].push_back({ y, c });
        graph[y].push_back({ x, c });
    }

    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        std::cin >> x;

        // Add paths with weight zero to dummy node
        graph[x].push_back({ DUMMY, 0 });
        graph[DUMMY].push_back({ x, 0 });
    }

    int q;
    std::cin >> q;
    vector<int> sources;
    for (int i = 0; i < q; i++) {
        std::cin >> x;
        sources.push_back(x);
    }

    vector<int> distances;
    // Run Dijkstra to find shortest paths
    dijkstra(DUMMY, distances, graph);

    for (int source : sources) {
        std::cout << distances[source] << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int from, to, weight;

    const bool operator<(const Edge& rhs) {
        return weight < rhs.weight;
    }
};

int kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    int cost = 0;
    vector<int> ids(n);
    for (int i = 0; i < n; i++) {
        ids[i] = i;
    }

    for (Edge edge : edges) {
        if (ids[edge.from] != ids[edge.to]) {
            cost += edge.weight;

            int oldID = ids[edge.from];
            int newID = ids[edge.to];
            for (int i = 0; i < n; i++) {
                if (ids[i] == oldID) {
                    ids[i] = newID;
                }
            }
        }
    }

    return cost;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    int x, y, c;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> c;
        edges.push_back({ x, y, c });
    }

    cout << kruskal(n, edges);

    return 0;
}

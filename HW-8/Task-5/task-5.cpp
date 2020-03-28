#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = 10000007;
const int wWeight = 2;
const int dWeight = 5;

struct Distance {
    int weight, distance;

    Distance operator+ (const Distance& rhs) {
        Distance res;
        res.weight = max(this->weight, rhs.weight);
        res.distance = this->distance + rhs.distance;
        return res;
    }

    friend const bool operator< (const Distance& lhs, const Distance& rhs) {
        if (lhs.weight * wWeight + lhs.distance * dWeight < rhs.weight * wWeight + rhs.distance * dWeight) {
            return true;
        }
        return false;
    }
};

struct pairCompare {
    const bool operator() (const pair<Distance, int>& lhs, const pair<Distance, int>& rhs) {
        if (rhs.first < lhs.first) {
            return true;
        }
        return false;
    }
};

void dijkstra(int node, int kilos, vector<Distance>& distances, vector<int>& parents, vector<vector<pair<int, Distance>>>& graph) {
    int n = graph.size();
    distances.assign(n, { INF, INF });
    parents.assign(n, -1);

    vector<bool> visited;
    visited.assign(n, false);

    distances[node] = { 0, 0 };
    priority_queue<pair<Distance, int>, vector<pair<Distance, int>>, pairCompare> q;
    q.push({ {0, 0}, node });
    while (!q.empty()) {
        int currNode = q.top().second;
        Distance currDist = q.top().first;
        q.pop();

        if (visited[currNode]) {
            continue;
        }
        visited[currNode] = true;

        for (auto neighbor : graph[currNode]) {
            int neighborNode = neighbor.first;
            Distance neighborDist = neighbor.second;

            if (neighborDist.weight > kilos) {
                continue;
            }

            Distance alternative = distances[currNode] + neighborDist;

            if (alternative < distances[neighborNode]) {
                distances[neighborNode] = alternative;
                parents[neighborNode] = currNode;
                q.push({ distances[neighborNode], neighborNode });
            }
        }
    }
}

int main() {
    int n, m, time;
    std::cin >> n >> m >> time;

    const int START = 0;
    const int FINISH = n - 1;

    vector<vector<pair<int, Distance>>> graph(n);
    int maxKilos = 0;

    int u, v, c, t;
    for (int i = 0; i < m; i++) {
        std::cin >> u >> v >> c >> t;
        u--; v--;

        graph[u].push_back({ v, {c, t} });

        if (c > maxKilos) {
            maxKilos = c;
        }
    }

    vector<Distance> distances;
    vector<int> parents;
    // Run a binary search for the kilograms
    int left = 0, right = maxKilos;
    int currentKilos = 0;

    int sucessfulKilos = maxKilos + 1;

    while (left <= right) {
        currentKilos = (left+right) / 2;
        dijkstra(START, currentKilos, distances, parents, graph);

        // If there is a path, try lower kilograms
        if (distances[FINISH].distance <= time) {
            right = currentKilos - 1;

            if (currentKilos < sucessfulKilos) {
                sucessfulKilos = currentKilos;
            }
        }
        // Else try with higher kilograms
        else {
            left = currentKilos + 1;
        }
    }

    // If it is possible, output kilos needed
    if (sucessfulKilos <= maxKilos) {
        std::cout << sucessfulKilos << "\n";
    }
    else {
        std::cout << "-1\n";
    }

    return 0;
}

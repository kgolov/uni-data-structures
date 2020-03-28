#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> leaders(n + 1);
    for (int i = 0; i <= n; i++) {
        leaders[i] = i;
    }

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;

        if (leaders[x] != leaders[y]) {
            int newLeader = leaders[x];
            int oldLeader = leaders[y];

            for (int i = 0; i <= n; i++) {
                if (leaders[i] == oldLeader) {
                    leaders[i] = newLeader;
                }
            }
        }
    }

    int q, input;
    cin >> q;
    vector<bool> result;
    for (int i = 0; i < q; i++) {
        cin >> input >> x >> y;

        if (input == 1) {
            if (leaders[x] == leaders[y]) {
                result.push_back(true);
            }
            else {
                result.push_back(false);
            }
        }
        else if (input == 2) {
            if (leaders[x] != leaders[y]) {
                int newLeader = leaders[x];
                int oldLeader = leaders[y];

                for (int i = 0; i <= n; i++) {
                    if (leaders[i] == oldLeader) {
                        leaders[i] = newLeader;
                    }
                }
            }
        }
    }

    for (bool b : result) {
        cout << b;
    }

    return 0;
}

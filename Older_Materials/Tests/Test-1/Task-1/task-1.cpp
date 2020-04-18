#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers;
    int num;

    for (int i = 0; i < n; i++) {
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());

    unordered_set<int> sums;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sums.insert(numbers[i] + numbers[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        if(sums.count(numbers[i])) {
            cout << "true";
            return 0;
        }
    }

    cout << "false";
    return 0;
}

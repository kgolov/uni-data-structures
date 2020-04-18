#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int toSearch;
    cin >> toSearch;
    int input;

    vector<int> indexes;
    vector<int> divisionsTotal;

    for (int i = 0; i < toSearch; i++) {
        cin >> input;

        int left = 0;
        int right = n - 1;
        int middle = left + (right - left) / 2;
        int foundAtIndex = -1;
        int divisions = 0;
        while (left <= right) {
            middle = left + (right - left) / 2;
            divisions++;

            if (input > arr[middle]) {
                left = middle + 1;
            }
            else if (input < arr[middle]) {
                right = middle - 1;
            }
            else {
                foundAtIndex = middle;
                break;
            }
        }

        indexes.push_back(foundAtIndex);
        divisionsTotal.push_back(divisions);
    }

    for (int idx : indexes) {
        cout << idx << " ";
    }
    cout << "\n";
    for (int divs : divisionsTotal) {
        cout << divs << " ";
    }

    return 0;
}

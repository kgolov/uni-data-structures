#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int queries;
    cin >> queries;
    int input;

    for (int i = 0; i < queries; i++) {
        cin >> input;

        int left = 0;
        int right = n - 1;
        int middle;
        int foundAtIndex = -1;
        while (left <= right) {
            middle = left + (right - left) / 2;

            if (input < arr[middle]) {
                right = middle - 1;
            }
            else if (input > arr[middle]) {
                left = middle + 1;
            }
            else {
                foundAtIndex = middle;
                break;
            }
        }

        if (foundAtIndex != -1) {
            int leftIndex = foundAtIndex;
            int rightIndex = foundAtIndex;

            while (leftIndex >= 0 && arr[leftIndex] == input) {
                leftIndex--;
            }
            leftIndex++;

            while (rightIndex < n && arr[rightIndex] == input) {
                rightIndex++;
            }
            rightIndex--;

            cout << leftIndex << " " << rightIndex << endl;
        }
        else {
            // We must find the first bigger one than the needed
            left = 0;
            right = n - 1;

            if (input > arr[right]) {
                cout << right + 1 << endl;
                continue;
            }

            int firstBigger = 0;

            while (left <= right) {
                middle = left + (right - left) / 2;

                if (arr[middle] > input) {
                    firstBigger = middle;
                    right = middle - 1;
                }
                else if (arr[middle] < input) {
                    left = middle + 1;
                }
            }

            cout << firstBigger << endl;
        }
    }

    return 0;
}

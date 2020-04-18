#include <bits/stdc++.h>

using namespace std;

struct Compare {
    bool operator()(int one, int two) {
        vector<int> oneDigits;
        vector<int> twoDigits;

        while (one) {
            int currDigit = one % 10;
            oneDigits.push_back(currDigit);
            one /= 10;
        }

        while (two) {
            int currDigit = two % 10;
            twoDigits.push_back(currDigit);
            two /= 10;
        }

        if (oneDigits.size() < twoDigits.size()) {
            return true;
        }
        else if (twoDigits.size() < oneDigits.size()) {
            return false;
        }
        else {
            int idx = 0;
            while (idx < oneDigits.size()) {
                if (oneDigits[idx] > twoDigits[idx]) {
                    return true;
                }
                idx++;
            }
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    int num;
    vector<int> numbers;

    for (int i = 0; i < n; i++) {
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end(), Compare());

    for (auto from : numbers) {
        cout << from;
    }

    return 0;
}

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

bool grade(int m, int n, vector<int> grades) {
    if (n == 0) {
        return true;
    }

    // Calculate average of all grades and see if it is larger than the required minimum
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += grades[i];
    }

    int average = sum / n;

    return (average >= m);
}


int main() {
    int m;
    int n;
    cin >> m;
    cin >> n;
    vector<int> grades;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        grades.push_back(input);
    }

    if (grade(m, n, grades)) {
        cout << "yes";
    }
    else {
        cout << "no";
    }


    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main() {
    string word;

    map<string, int> occurences;

    while(cin >> word) {
        occurences[word]++;
    }

    for (auto element : occurences) {
        if (element.second == 1) {
            std::cout << element.first << "\n";
        }
    }

    return 0;
}

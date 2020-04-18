#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    std::cin >> n;

    int input;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        std::cin >> input;

        mp[input]++;
        if(mp[input] == 10) {
            mp[input] = 0;
        }
    }

    int users = 0;
    int products = 0;

    unordered_map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); ++it) {
        if (it->second > 0) {
            users++;
            products += it->second;
        }
    }

    std::cout << users << " " << products;

    return 0;
}

#include <iostream>
#include <string>

using std::string;

bool areSimilar(string& one, string& two) {
    int letters1[26] = {};
    int letters2[26] = {};

    for (int i = 0; i < one.length(); i++) {
        letters1[one[i] - 'a']++;
    }
    for (int i = 0; i < two.length(); i++) {
        letters2[two[i] - 'a']++;
    }

    // Check both arrays
    bool flag = true;
    for (int i = 0; i < 26; i++) {
        if (letters1[i] != letters2[i]) {
            flag = false;
        }
    }

    return flag;
}

int main() {
    int n;
    std::cin >> n;
    string s1, s2;
    s1.resize(n);
    s2.resize(n);
    std::cin >> s1;
    std::cin >> s2;

    if (areSimilar(s1, s2)) {
        std::cout << "yes";
    }
    else {
        std::cout << "no";
    }

    return 0;
}

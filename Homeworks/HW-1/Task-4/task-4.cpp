#include <iostream>
#include <vector>

bool cloningSocks(int normalTarget, int copiesTarget) {
    int normal = 1;
    int copies = 0;

    while (normal < normalTarget) {
        // Run normal copying
        normal++;
        copies++;
    }

    // We now get the exact number of normal socks
    // See if we can get the number of copies

    if (copies > 0) {
        while (copiesTarget > copies) {
            copies += 2;
        }
    }

    // Check if we have enough or more
    if (normal == normalTarget && copies == copiesTarget) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int t;
    std::cin >> t;

    std::vector<bool> output;

    for (int i = 0; i < t; i++) {
        int n;
        int m;

        std::cin >> n;
        std::cin >> m;

        bool result = cloningSocks(m, n);

        output.push_back(result);
    }

    for (int i = 0; i < t; i++) {
        if (output[i]) {
            std::cout << "yes" << std::endl;
        }
        else {
            std::cout << "no" << std::endl;
        }
    }

    return 0;
}

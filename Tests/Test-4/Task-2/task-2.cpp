#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class segmentTree {
    pair<int, int>* tree = nullptr;
    int treeSize = 0;
    vector<pair<int, int>> values;

    const int getParent(int index) const {
        return (index - 1) / 2;
    }

    const int leftChild(int index) const {
        return (2 * index) + 1;
    }

    const int rightChild(int index) const {
        return (2 * index) + 2;
    }

    const bool hasLeft(int index) const {
        if (leftChild(index) >= treeSize) {
            return false;
        }
        else if (tree[leftChild(index)].first != INT_MIN) {
            return true;
        }
        else {
            return false;
        }
    }

    const bool hasRight(int index) const {
        if (rightChild(index) >= treeSize) {
            return false;
        }
        else if (tree[rightChild(index)].first != INT_MIN) {
            return true;
        }
        else {
            return false;
        }
    }

    void build(int currentIndex, int leftIndex, int rightIndex) {
        if (leftIndex == rightIndex) {
            tree[currentIndex] = values[leftIndex];
        }
        else {
            int mid = (leftIndex + rightIndex) / 2;
            build(leftChild(currentIndex), leftIndex, mid);
            build(rightChild(currentIndex), mid + 1, rightIndex);

            int lowerb = tree[leftChild(currentIndex)].first;
            int higherb = 0;

            if (tree[leftChild(currentIndex)].second > tree[rightChild(currentIndex)].second) {
                higherb = tree[leftChild(currentIndex)].second;
            }
            else {
                higherb = tree[rightChild(currentIndex)].second;
            }

            tree[currentIndex] = make_pair(lowerb, higherb);
        }
    }

    const int _count(int value, int index) const {
        int counter = 0;

        if (tree[index].first <= value && tree[index].second >= value) {
            if (hasLeft(index) && hasRight(index)) {
                counter += _count(value, leftChild(index));
                counter += _count(value, rightChild(index));

                return counter;
            }
            else if (hasLeft(index) && !hasRight(index)) {
                counter += _count(value, leftChild(index));

                return counter;
            }
            else {
                return 1;
            }
        }
        else {
            return 0;
        }
    }

public:
    segmentTree(const vector<pair<int, int>>& values) {
        this->values = values;
        treeSize = 4 * values.size();
        tree = new pair<int, int>[treeSize];

        for (int i = 0; i < treeSize; i++) {
            tree[i] = make_pair(INT_MIN, INT_MIN);
        }

        build(0, 0, this->values.size() - 1);
    }

    ~segmentTree() {
        delete tree;
    }

    const int count(int value) const {
        return _count(value, 0);
    }
};


int main() {
    int n, q;
    std::cin >> n >> q;
    int start, end, input;

    vector<pair<int, int>> intervals;

    for (int i = 0; i < n; i++) {
        std::cin >> start >> end;

        pair<int, int> input = make_pair(start, end);
        intervals.push_back(input);
    }

    std::sort(intervals.begin(), intervals.end());

    // Build segment tree
    segmentTree tree(intervals);

    for (int i = 0; i < q; i++) {
        std::cin >> input;

        std::cout << tree.count(input) << " ";
    }

    return 0;
}

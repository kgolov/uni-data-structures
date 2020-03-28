#include <iostream>

class BST;
int searchInDepth(BST* tree, int value, int level);

class BST {
public:
    int value;
    BST* left = nullptr;
    BST* right = nullptr;

    BST(int value) {
        this->value = value;
    }

    ~BST() {
        delete left;
        delete right;
    }

    void add(int value) {
        if (value < this->value) {
            if (left == nullptr) {
                left = new BST(value);
            }
            else {
                left->add(value);
            }
        }
        else if (value > this->value) {
            if (right == nullptr) {
                right = new BST(value);
            }
            else {
                right->add(value);
            }
        }
    }

    int distanceToRoot(int value) {
        return searchInDepth(this, value, 0);
    }
};

int searchInDepth(BST* tree, int value, int level) {
    // If the element is not found, return -1
    if (tree == nullptr) {
        return -1;
    }

    // If we have found the element, return the level we are on
    if (value == tree->value) {
        return level;
    }
    else if (value < tree->value) {
        // Search in left subtree
        int leftDepth = searchInDepth(tree->left, value, level + 1);
        return leftDepth;
    }
    else if (value > tree->value) {
        // Search in right subtree
        int rightDepth = searchInDepth(tree->right, value, level + 1);
        return rightDepth;
    }

    return -1;
}

int main() {
    int streets;
    std::cin >> streets;
    int search;
    std::cin >> search;
    int input;
    std::cin >> input;
    BST streetNumbers(input);

    for (int i = 1; i < streets; i++) {
        std::cin >> input;
        streetNumbers.add(input);
    }

    int* toSearch = new int[search];

    for (int i = 0; i < search; i++) {
        std::cin >> toSearch[i];
    }

    for (int i = 0; i < search; i++) {
        std::cout << streetNumbers.distanceToRoot(toSearch[i]) << std::endl;
    }

    delete[] toSearch;
    return 0;
}

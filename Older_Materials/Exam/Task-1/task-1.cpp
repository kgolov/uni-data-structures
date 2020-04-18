#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int value) {
        this->value = value;
    }

    void add(int value) {
        if (value < this->value) {
            if (left) {
                left->add(value);
            }
            else {
                left = new Node(value);
            }
        }
        else if (value > this->value) {
            if (right) {
                right->add(value);
            }
            else {
                right = new Node(value);
            }
        }
    }

    void print() {
        cout << value << " ";
        if (left) {
            left->print();
        }
        if (right) {
            right->print();
        }
    }
};

int main() {
    int n;
    cin >> n;
    string input;
    int num;

    Node* tree = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> input;

        if (input == "add") {
            cin >> num;

            if (tree) {
                tree->add(num);
            }
            else {
                tree = new Node(num);
            }
        }
        else if (input == "print") {
            if (tree) {
                tree->print();
            }
        }
    }

    return 0;
}

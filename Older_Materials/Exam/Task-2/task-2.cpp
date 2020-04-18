#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    int level;

    Node(int value, int level = 1) {
        this->value = value;
        this->level = level;
    }

    void add(int value) {
        if (value < this->value) {
            if (left) {
                left->add(value);
            }
            else {
                left = new Node(value, level + 1);
            }
        }
        else if (value > this->value) {
            if (right) {
                right->add(value);
            }
            else {
                right = new Node(value, level + 1);
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

    void print_odd_layers() {
        queue<Node*> q;
        q.push(this);
        while(!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->level % 2 == 1) {
                cout << current->value << " ";
            }

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
    }

    Node* remove(Node* current, int value) {
        if (current == nullptr) {
            return nullptr;
        }

        if(value < current->value) {
            current->left = remove(current->left, value);
        }
        else if (value > current->value) {
            current->right = remove(current->right, value);
        }
        else {
            if (!current->left && !current->right) {
                delete current;
                return nullptr;
            }
            else if(!current->left && current->right) {
                Node* oldRight = current->right;
                delete current;
                return oldRight;
            }
            else if(current->left && !current->right) {
                Node* oldLeft = current->left;
                delete current;
                return oldLeft;
            }
            else {
                Node* toSwap = current->right;
                while (toSwap->left != nullptr) {
                    toSwap = toSwap -> left;
                }

                current->value = toSwap->value;
                current->right = remove(current->right, toSwap->value);
            }
        }

        return current;
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
        else if (input == "print_odd_layers") {
            if (tree) {
                tree->print_odd_layers();
            }
        }
        else if (input == "remove") {
            cin >> num;

            if (tree) {
                tree = tree->remove(tree, num);
            }
        }
    }

    return 0;
}

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node {
    double value;
    int height;
    Node* left;
    Node* right;

    Node(double value, Node* left = nullptr, Node* right = nullptr) : height(0)    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    const int bfactor() const {
        int leftH, rightH;

        if (left != nullptr) {
            leftH = left->height + 1;
        }
        else {
            leftH = 0;
        }

        if (right != nullptr) {
            rightH = right->height + 1;
        }
        else {
            rightH = 0;
        }

        return rightH - leftH;
    }

    void updateHeight() {
        height = 0;

        if (left != nullptr) {
            if (left->height + 1 > height) {
                height = left->height + 1;
            }
        }

        if (right != nullptr) {
            if (right->height + 1 > height) {
                height = right->height + 1;
            }
        }
    }

    void leftRotation() {
        if (right == nullptr) {
            return;
        }

        Node* rightLeft = right->left;
        Node* oldLeft = left;
        swap(this->value, right->value);
        left = right;
        right = right->right;
        left->right = rightLeft;
        left->left = oldLeft;

        if (left != nullptr) {
            left->updateHeight();
        }
        updateHeight();
    }

    void rightRotation() {
        if (left == nullptr) {
            return;
        }

        Node* leftRight = left->right;
        Node* oldRight = right;

        swap(this->value, left->value);
        right = left;
        left = left->left;
        right->left = leftRight;
        right->right = oldRight;

        if (right != nullptr) {
            right->updateHeight();
        }
        updateHeight();
    }

    void balance() {
        if (bfactor() > 1) {
            if (right->bfactor() >= 1) {
                leftRotation();
            }
            else if (right->bfactor() <= 1) {
                right->rightRotation();
                leftRotation();
            }
        }
        else if (bfactor() < -1) {
            if (left->bfactor() <= 1) {
                rightRotation();
            }
            else if (left->bfactor() >= 1) {
                left->leftRotation();
                rightRotation();
            }
        }
    }

    void addRecursive(double value) {
        if (value < this->value) {
            if (left != nullptr) {
                left->addRecursive(value);
            }
            else {
                left = new Node(value);
            }
        }
        else if (value > this->value) {
            if (right != nullptr) {
                right->addRecursive(value);
            }
            else {
                right = new Node(value);
            }
        }
        else {
            cout << value << " already added" << std::endl;
        }
        updateHeight();
        balance();
    }

    void removeRecursive(double value) {
        if (value < this->value) {
            if (left != nullptr) {
                if (left->value == value && left->left == nullptr && left->right == nullptr) {
                    delete left;
                    left = nullptr;
                }
                else {
                    left->removeRecursive(value);
                }
            }
            else {
                cout << value << " not found to remove" << endl;
            }
        }
        else if (value > this->value) {
            if (right != nullptr) {
                if (right->value == value && right->left == nullptr && right->right == nullptr) {
                    delete right;
                    right = nullptr;
                }
                else {
                    right->removeRecursive(value);
                }
            }
            else {
                cout << value << " not found to remove" << endl;
            }
        }
        else if (value == this->value) {
            if (left == nullptr && right != nullptr) {
                this->value = right->value;
                left = right->left;
                right = right->right;
            }
            else if (left != nullptr && right == nullptr) {
                this->value = left->value;
                right = left->right;
                left = left->left;
            }
            else if (left != nullptr && right != nullptr) {
                Node* current = right;
                while (current->left != nullptr) {
                    current = current->left;
                }
                this->value = current->value;

                if (right != nullptr && right->left == nullptr && right->right == nullptr) {
                    delete right;
                    right = nullptr;
                }
                else {
                    right->removeRecursive(this->value);
                }
            }
        }
        updateHeight();
        balance();
    }
};

class AVLTree {
private:
    Node* root;

    bool containsRecursive(Node* current, double value) {
        if (current == nullptr) {
            return false;
        }

        if (current->value == value) {
            return true;
        }

        if (value < current->value) {
            return containsRecursive(current->left, value);
        }
        else {
            return containsRecursive(current->right, value);
        }
    }

    void printRecursive(Node* current) {
        if (current == nullptr) {
            return;
        }

        printRecursive(current->left);
        cout << current->value << " ";
        printRecursive(current->right);
    }

public:
    AVLTree() {
        root = nullptr;
    }

    bool contains(double value) {
        if (root == nullptr) {
            return false;
        }

        return containsRecursive(root, value);
    }

    void print() {
        if (root == nullptr) {
            return;
        }

        printRecursive(root);
        cout << endl;
    }

    void add(double value) {
        if (root != nullptr) {
            root->addRecursive(value);
        }
        else {
            root = new Node(value);
        }
    }

    void remove(double value) {
        if (root != nullptr) {
            if (value == root->value) {
                if (root->left == nullptr && root->right == nullptr) {
                    delete root;
                    root = nullptr;
                }
                else if (root->left == nullptr && root->right != nullptr) {
                    root->value = root->right->value;
                    root->left = root->right->left;
                    root->right = root->right->right;
                }
                else if (root->left != nullptr && root->right == nullptr) {
                    root->value = root->left->value;
                    root->right = root->left->right;
                    root->left = root->left->left;
                }
                else if (root->left != nullptr && root->right != nullptr) {
                    Node* current = root->right;
                    while (current->left != nullptr) {
                        current = current->left;
                    }
                    root->value = current->value;

                    if (root->right != nullptr && root->right->left == nullptr && root->right->right == nullptr) {
                        delete root->right;
                        root->right = nullptr;
                    }
                    else {
                        root->right->removeRecursive(root->value);
                    }
                }
            }
            else {
                root->removeRecursive(value);
            }
        }
        else {
            cout << value << " not found to remove" << endl;
        }
    }
};

int main() {
    AVLTree tree;
    string operation;
    double number;
    int N;

    cin >> N;
    cout << fixed;

    for (int i = 0; i < N; i++) {
        cin >> operation;
        if (operation != "print") {
            cin >> number;
        }

        if (operation == "add") {
            tree.add(number);
        }
        else if (operation == "remove") {
            tree.remove(number);
        }
        else if (operation == "contains") {
            if (tree.contains(number)) {
                cout << "yes" << endl;
            }
            else {
                cout << "no" << endl;
            }
        }
        else if (operation == "print") {
            tree.print();
        }
    }

    return 0;
}

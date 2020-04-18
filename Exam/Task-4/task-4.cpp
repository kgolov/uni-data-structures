#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    int level;
    Node(int value, int level) {
        this->value = value;
        this->level = level;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value, 0);
    }

    void printLeftProfile() {
      //TODO: implement this function
        queue<Node*> q;
        q.push(root);

        int lastPrintedLevel = -1;
        while(!q.empty()) {
            Node* current = q.front();
            q.pop();

            if(current->level > lastPrintedLevel) {
                cout << current->value << " ";
                lastPrintedLevel = current->level;
            }

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
    }

private:
  	//you can write helper functions if needed
    Node* root;

    Node* insert(Node *curNode, int value, int level) {
        if (curNode == NULL) {
            curNode = new Node(value, level + 1);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value, curNode->level);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value, curNode->level);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    tree.printLeftProfile();
    return 0;
}

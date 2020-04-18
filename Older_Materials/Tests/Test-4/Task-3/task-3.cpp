#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *leftNode;
        Node *rightNode;
        Node(int d) {
            data = d;
            leftNode = NULL;
            rightNode = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->leftNode, data);
                    root->leftNode = cur;
                } else {
                    cur = insert(root->rightNode, data);
                    root->rightNode = cur;
               }

               return root;
           }
        }


	void leaves(Node *root) {


        int sum = 0;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current != nullptr) {
                if (current->leftNode == nullptr && current->rightNode == nullptr) {
                    // This is a leaf
                    if (current->data % 2 != 0) {
                        // It is odd, so add it to the sum
                        sum += current->data;
                    }
                }

                if (current->leftNode != nullptr) {
                    q.push(current->leftNode);
                }
                if (current->rightNode != nullptr) {
                    q.push(current->rightNode);
                }
            }
        }

        std::cout << sum;
    }


}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

	myTree.leaves(root);
    return 0;
}

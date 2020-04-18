#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    Node * next;
    int data;
    Node(Node* _next,int _data){
        next = _next;
        data = _data;
    }
};
class LinkedList{
    public:
    LinkedList(){
        head = NULL;
    }
    ~LinkedList(){
        Node* tmp;
        while(head!=NULL){
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    void add(int number){
        Node *tmp = new Node(head,number);
        head = tmp;
    }
    void print(){
        Node* curr = head;
        while(curr!=NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    void removeComplex(int devidedBy){
        //  TODO: write your code here

        // See if we need to delete head
        // Careful if the list has become empty
        while (head != nullptr && head->data % devidedBy == 0) {
            // Delete head
            Node* newHead = head->next;
            delete head;
            head = newHead;
        }

        // We can now start from the second element after the head
        Node* prev = head;
        Node* curr = head->next;
        while (curr != nullptr) {
            if (curr->data % devidedBy == 0) {
                // Link the previous element to the next one
                prev->next = curr->next;
                delete curr;
                // Update our current element to the next one
                curr = prev->next;
            }
            else {
                // Shift prev and curr pointers by one
                prev = curr;
                curr = curr->next;
            }
        }
    } // end removeComplex
    private:
    Node* head;
};
int main(){
    LinkedList l;

    int n;
    cin >> n;
    int number;
    for(int i = 0 ; i < n ; i++){
        cin >>number;
        l.add(number);
    }
    int devidedBy;
    cin >> devidedBy;
    l.removeComplex(devidedBy);
    l.print();
}

// Complete the insertNodeAtPosition function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* ptr = head;
    for (int i = 0; i < position - 1; i++) {
        ptr = ptr->next;
    }

    SinglyLinkedListNode* newNode = new SinglyLinkedListNode { data };
    newNode->next = ptr->next;
    ptr->next = newNode;

    return head;
}

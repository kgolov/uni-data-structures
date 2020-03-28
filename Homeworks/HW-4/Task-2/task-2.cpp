// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if (position == 0) {
        // We need to delete the head
        SinglyLinkedListNode* newHead = head->next;
        free(head);
        return newHead;
    }
    else {
        // We can delete normally
        SinglyLinkedListNode* ptr = head;
        for (int i = 0; i < position - 1; i++) {
            ptr = ptr->next;
        }
        SinglyLinkedListNode* newNext = ptr->next->next;
        delete(ptr->next);
        ptr->next = newNext;
        return head;
    }
}

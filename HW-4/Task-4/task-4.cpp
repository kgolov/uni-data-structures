// Complete the reverse function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->next == nullptr) {
        return head;
    }

    SinglyLinkedListNode* prev = head;
    SinglyLinkedListNode* current = prev->next;
    SinglyLinkedListNode* next = current->next;

    head->next = nullptr;

    while (current != nullptr) {
        current->next = prev;
        prev = current;
        current = next;

        if (next != nullptr) {
            next = next->next;
        }
    }

    return prev;
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }

    SinglyLinkedListNode* newHead;
    SinglyLinkedListNode* ptr1 = head1;
    SinglyLinkedListNode* ptr2 = head2;

    // We will make ptr1 our new head
    if (head1->data < head2->data) {
        newHead = head1;
        ptr1 = ptr1->next;
    } else {
        newHead = head2;
        ptr2 = ptr2->next;
    }

    SinglyLinkedListNode* ptr = newHead;

    while (ptr1 != nullptr && ptr2 != nullptr) {
        if (ptr1->data < ptr2->data) {
            ptr->next = ptr1;
            ptr = ptr->next;
            ptr1 = ptr1->next;
        }
        else {
            ptr->next = ptr2;
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
    }

    while (ptr1 != nullptr) {
        ptr->next = ptr1;
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }

    while (ptr2 != nullptr) {
        ptr->next = ptr2;
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }

    return newHead;
}

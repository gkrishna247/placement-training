void reorderList(struct ListNode* head) {
    if (!head || !head->next) return;
    struct ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *second = slow->next;
    slow->next = NULL;
    struct ListNode *prev = NULL, *curr = second;
    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    struct ListNode *first = head;
    second = prev;
    while (second) {
        struct ListNode *tmp1 = first->next, *tmp2 = second->next;
        first->next = second;
        second->next = tmp1;
        first = tmp1;
        second = tmp2;
    }
}

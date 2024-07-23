struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummy = {0, head}, *prev = &dummy;
    while (prev->next && prev->next->next) {
        struct ListNode* a = prev->next;
        struct ListNode* b = a->next;
        a->next = b->next;
        b->next = a;
        prev->next = b;
        prev = a;
    }
    return dummy.next;
}

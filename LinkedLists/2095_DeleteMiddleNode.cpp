// 2095. Delete the Middle Node of a Linked List

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteMiddle(ListNode* head) {
    // Edge case: if the list only has one node, return nullptr.
    if (!head || !(head->next)) {
        return nullptr;
    }

    ListNode* slowPointer = head;
    ListNode* fastPointer = head->next->next;
    
    // Find the middle node
    while (fastPointer && fastPointer->next) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
    }

    // Delete the middle node
    slowPointer->next = slowPointer->next->next;

    return head;
}
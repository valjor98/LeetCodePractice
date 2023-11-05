// 206. Reverse Linked List


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* reverseList(ListNode* head) {
    ListNode* aux = nullptr;
    while(head){
        ListNode* Node = new ListNode(head->val, aux);
        aux = Node;
        head = head->next;
    }
    return aux; 
}
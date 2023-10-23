// 0021 Merge Two Sorted Linked List
// Two Pointers, linked list

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode* placeholder = new ListNode();
    ListNode* tail = placeholder;
    ListNode* pointer1 = list1;
    ListNode* pointer2 = list2;

    while (pointer1 && pointer2){
        if (pointer1->val < pointer2->val) {
            tail->next = pointer1;
            pointer1 = pointer1->next;
        }
        else {
            tail->next = pointer2;
            pointer2 = pointer2->next;
        }
        tail = tail->next;
    }

    if (pointer1){
        tail->next = pointer1;
    }
    else if (pointer2){
        tail->next = pointer2;
    }

    return placeholder->next; 

}

int main(){
    // 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);      // creates pointer list1 which points to the new node(1)
    list1->next = new ListNode(2);          // sets the next pointer of node(1) to point to new node node(2)
    list1->next->next = new ListNode(4);    // sets the next pointer of node(2) to point to new node node(4)

    // 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* answer = mergeTwoLists(list1, list2);
    while (answer){
        cout << answer->val << " ";
        answer = answer->next;
    }


    return 0;
}
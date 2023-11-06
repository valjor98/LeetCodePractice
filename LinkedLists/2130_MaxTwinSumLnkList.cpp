// 2130. Maximum Twin Sum of a Linked List

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int pairSum(ListNode* head) {
    if(!head){
        return 0;
    }
    queue<int> queue;
    int maxV = 0;
    ListNode* aux = nullptr;
    ListNode* prevHead = nullptr;
    while(head){
        queue.push(head->val);
        aux = prevHead;
        prevHead = head; 
        head = head->next;
        prevHead->next = aux;

    }
    while(prevHead){
        int candSum = prevHead->val + queue.front();
        queue.pop();
        maxV = max(maxV, candSum);
        prevHead = prevHead->next;
    }
    return maxV;
}
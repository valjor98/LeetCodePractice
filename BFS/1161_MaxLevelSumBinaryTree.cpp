// 1161. Maximum Level Sum of a Binary Tree
// BFS, Binary tree traversal
// O(n)

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxLevelSum(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int maxV = INT_MIN;
    int maxL = 0;
    int level = 0;
    if(!root) return {};

    while(!q.empty()){
        level++;
        int n = q.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            TreeNode* Node = q.front();
            q.pop();
            sum += Node->val;
            if(Node->left){
                q.push(Node->left);
            }
            if(Node->right){
                q.push(Node->right);
            }
        }
        if(maxV < sum){
            maxV = sum;
            maxL = level;
        }
    }
    return maxL;
}
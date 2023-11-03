// 1448. Count Good Nodes in Binary Tree
// BST

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solve(TreeNode* root,int hi){
    if (root){
        int k=solve(root->left, max(hi,root->val)) + solve(root->right, max(hi,root->val));
        if (root->val>=hi){
            k++;
        }
        return k;
    }
    return 0;
}
int goodNodes(TreeNode* root) {
    return solve(root,INT_MIN);
}     
// 1372. Longest ZigZag Path in a Binary Tree
// DST, Recursivity

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

int maxLength=0;

void solve(TreeNode* root,int dir,int currLength){
    if(!root) return;
    maxLength=max(maxLength,currLength);
    solve(root->left,0,dir?currLength+1:1);
    solve(root->right,1,dir?1:currLength+1);
}

int longestZigZag(TreeNode* root) {
    solve(root,0,0);
    solve(root,1,0);
    return maxLength;
}
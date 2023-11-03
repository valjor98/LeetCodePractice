//437. Path Sum III
// BST

// Time Complexity: O(N^2) in the worst case for an unbalanced tree, because for every node, we're exploring all possible paths down the tree. For a balanced tree, it would be O(NlogN).
// Space Complexity: O(N) for the recursion stack space in the case of a skewed tree. In the average case, it would be O(logN) for a balanced tree due to the height of the tree.

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

int ans=0;
int pathSum(TreeNode* root, int sum) {
    if(root){
        dfs(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
    }
    return ans;
}
void dfs(TreeNode* root, int sum){
    if(!root)return;
    if(root->val == sum)ans++;
    dfs(root->left, sum-root->val);
    dfs(root->right, sum-root->val);
}
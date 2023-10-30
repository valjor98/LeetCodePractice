// 111. Minimum Depth of Binary Tree
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


int minDepth(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    if(!root){
        return level;
    }

    while(!q.empty()){
        level++;
        int n = q.size();
        for(int i=0; i<n; i++){
            TreeNode* node = q.front();
            q.pop();
            if(!(node->left) && !(node->right)){
                return level;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }

        }
    }
    return level;
}
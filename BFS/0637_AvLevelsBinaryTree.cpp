// 637. Average of Levels in Binary Tree
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

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> result;
    queue<TreeNode*> q;
    q.push(root);

    if(!root){
        return result;
    }
    while(!q.empty()){
        int n = q.size();
        double sum = 0;
        for(int i=0; i<n; i++){
            TreeNode* node = q.front();
            q.pop();
            sum += node->val;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        double av = double(sum)/n;
        result.push_back(av);
    }
    return result;        
}
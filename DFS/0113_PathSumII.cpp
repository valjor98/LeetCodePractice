// 113 Path Sum II
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

void DFS(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int> vect){
    // Base case, terminating condition
    if(root == NULL){
        return;
    }
    else{
        int aux = targetSum - root->val;
        vect.push_back(root->val);

        if( !root->left && !root->right  && aux==0){
            ans.push_back(vect);
        }
        DFS(root->left, aux, ans, vect);
        DFS(root->right, aux, ans, vect);
    }
}


vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int> vect{};
    vector<vector<int>> ans{};
    DFS(root, targetSum, ans, vect);
    return ans;
}
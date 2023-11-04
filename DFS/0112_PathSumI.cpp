// 112 Path Sum I
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

bool flag = false;
bool hasPathSumOG(TreeNode* root, int targetSum) {
    if(root == NULL){
        cout << "hit false 1" << endl;
    }
    else{
        int aux = targetSum - root->val;
        if( !root->left && !root->right  && aux==0){
            flag = true;
        }
        hasPathSumOG(root->left, aux);
        hasPathSumOG(root->right, aux);
    }
    return flag;
}


// better version
bool hasPathSum(TreeNode* root, int targetSum) {
    // Base case, terminating condition
    if(root == NULL){
        return false;
    }
    else{
        // Keep track of 
        int aux = targetSum - root->val;
        if( !root->left && !root->right  && aux==0){
            return true;
        }
        return hasPathSum(root->left, aux) || hasPathSum(root->right, aux);
    }
}
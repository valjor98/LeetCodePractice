//700. Search in a Binary Search Tree
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


TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* current = root;
    while (current != NULL) {
        // Node found
        if (current->val == val){ 
            return current ;  
        }
        // Search left subtree
        if (current->val > val){
            current = current->left; 
        } 
        // Search right subtree
        else{
            current = current->right;
        }
    }
    return NULL; // Node not found   
}

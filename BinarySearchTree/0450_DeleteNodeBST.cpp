// 450. Delete Node in a BST
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

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root)
        //We recursively call the function until we find the target node
        if(key < root->val){
            root->left = deleteNode(root->left, key);     
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        // we find the val      
        else{
            //No child condition
            if(!root->left && !root->right){
                return NULL; 
            }     
            //One child contion -> replace the node with it's child    
            if (!root->left || !root->right){
                return root->left ? root->left : root->right;
            }    
            //Two child condition   

            //(or) TreeNode *temp = root->right;
            TreeNode* temp = root->left;                     
            //while(temp->left != NULL) temp = temp->left;
            while(temp->right != NULL){
                temp = temp->right; 
            }
            // root->val = temp->val;
            root->val = temp->val;                    
            // root->right = deleteNode(root->right, temp);	        
            root->left = deleteNode(root->left, temp->val); 	
        }
    return root;
}
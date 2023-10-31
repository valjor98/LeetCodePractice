// 199. Binary Tree Right Side View
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


vector<int> rightSideView(TreeNode* root) {
    if (!root) return {};

    vector<int> answer;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        vector<int> aux;
        for(int i=0; i<n; i++){
            TreeNode* Node = q.front();
            q.pop();
            aux.push_back(Node->val);
            if(Node->left){
                q.push(Node->left);
            }
            if(Node->right){
                q.push(Node->right);
            }
        }
        answer.push_back(aux.back());
    }

    return answer;
}
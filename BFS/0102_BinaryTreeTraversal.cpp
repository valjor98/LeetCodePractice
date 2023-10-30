// 102. Binary Tree Level Order Traversal
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

vector<vector<int>> levelOrder(TreeNode* root) {
        // Return empty vector if root is null
        if (!root) return {};

        // Initialize result vector and queue for BFS
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        // Start BFS
        while (!q.empty()) {
            // Calculate the number of nodes at the current level
            int n = q.size();
            // Initialize a new vector to store this level's nodes
            vector<int> level;

            // Iterate through each node at the current level
            for (int i = 0; i < n; ++i) {
                // Pop the front node from the queue
                TreeNode* node = q.front();
                q.pop();

                // Add the node's value to the current level's vector
                level.push_back(node->val);

                // Add non-null children to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // Add the current level's vector to the final result
            result.push_back(level);
        }

        return result;
    }
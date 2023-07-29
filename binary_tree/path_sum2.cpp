/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private: 
    // 记录所有路径的回溯。
    void backtracking(TreeNode* root, vector<vector<int>>& paths, vector<int>& path, int targetSum) {
        if (root->left == nullptr && root->right == nullptr) {
            path.push_back(root->val);
            if (accumulate(path.begin(), path.end(), 0) == targetSum) {
                paths.push_back(path);
                return;
            }
            return;
        }
        // 单层处理逻辑，将当前结点的值放入path中。
        path.push_back(root->val);
        if (root->left) {
            backtracking(root->left, paths, path, targetSum);
            path.pop_back();
        }
        if (root->right) {
            backtracking(root->right, paths, path, targetSum);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        if (root == nullptr) {
            return paths;
        }
        backtracking(root, paths, path, targetSum);
        return paths;
    }
};
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
//  leetcode 872
class Solution {
private: 
    void dfs(vector<int>& res, TreeNode* root) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            res.push_back(root->val);
            return;
        }
        dfs(res, root->left);
        dfs(res, root->right);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1_path;
        vector<int> root2_path;
        dfs(root1_path, root1);
        dfs(root2_path, root2);
        for (int i = 0; i < root1_path.size(); i++) {
            if (root1_path[i] != root2_path[i]) {
                return false;
            }
        }
        return root1_path.size() == root2_path.size();
    }
};
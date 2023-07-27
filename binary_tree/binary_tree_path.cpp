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
private: void backtracking(TreeNode* root, vector<string>& res, vector<int>& path) {
    // 单层处理逻辑
    path.push_back(root->val);
    // 到叶子结点了，收集结果。
    if (!root->left && !root->right) {
        string string_temp;
        for (int i = 0; i < path.size() - 1; i++) {
            string_temp += to_string(path[i]);
            string_temp += "->";
        }
        string_temp += to_string(path[path.size() - 1]);
        res.push_back(string_temp);
    }
    if (root->left) {
        backtracking(root->left, res, path);
        path.pop_back();
    }
    if (root->right) {
        backtracking(root->right, res, path);
        path.pop_back();
    }
    
}
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if (root == nullptr) {
            return res;
        }
        backtracking(root, res, path);
        return res;
    }
};
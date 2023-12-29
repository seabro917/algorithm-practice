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
//  leetcode 993
class Solution {
private:
    int x;
    int y;
    int x_depth = 0, y_depth = 0;
    TreeNode* x_parent;
    TreeNode* y_parent;
    void dfs(TreeNode* cur, int depth, TreeNode* parent) {
        if (!cur) {
            return;
        }
        // 找到了x
        if (cur->val == x) {
            x_depth = depth;
            x_parent = parent;
        }
        if (cur->val == y) {
            y_depth = depth;
            y_parent = parent;
        }
        dfs(cur->left, depth + 1, cur);
        dfs(cur->right, depth + 1, cur);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x;
        this->y = y;
        dfs(root, 0, nullptr);
        return x_depth == y_depth && x_parent != y_parent;
    }
};
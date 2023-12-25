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

// leetcode 129
// dfs写法,自顶向下
class Solution {
private:
    int sum = 0;
    void dfs(TreeNode* root, int pre_sum) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            sum += pre_sum * 10 + root->val;
            return;
        }
        dfs(root->left, pre_sum * 10 + root->val);
        dfs(root->right, pre_sum * 10 + root->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
};

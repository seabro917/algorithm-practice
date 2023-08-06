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

// leetcode 538
class Solution {
private:
    TreeNode* pre = new TreeNode(0);
    // 反中序遍历：右-->中-->左
    void traversal(TreeNode* root) {
        if (!root) {
            return;
        }
        traversal(root->right);
        root->val += pre->val;
        pre = root;
        traversal(root->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
};
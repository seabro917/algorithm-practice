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

// leetcode 669
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) {
            return nullptr;
        }
        if (root->val > high) {
            // 这里和BST内删除结点不同, 删除结点那题是只删除一个,所以做完操作之后直接返回即可,这里在树内可能存在多个需要被操作删除的结点,所以判断内要递归处理.
            return trimBST(root->left, low, high);
        }
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high); 
        return root;
    }
};
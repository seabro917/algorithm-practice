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




// 核心思想就是如果一个树是完全二叉树，那么从根节点遍历所有左边和遍历所有右边，得到的深度一定相等(因为最后一层所有结点都在左侧)。
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        TreeNode* left_node = root->left;
        TreeNode* right_node = root->right; 
        int left_depth = 0, right_depth = 0;
        while (left_node) {
            left_depth++;
            left_node = left_node->left;
        }
        while (right_node) {
            right_depth++;
            right_node = right_node->right;
        }
        if (left_depth == right_depth) {
            return (2 << left_depth) - 1;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// 不考虑完全二叉树性质的普通迭代法。
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
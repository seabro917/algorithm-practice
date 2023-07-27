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
    int getHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_height = getHeight(root->left);
        if (left_height == -1) {
            return -1;
        }
        int right_height = getHeight(root->right);
        if (right_height == -1) {
            return -1;
        }
        // 如果当前结点的左右子树的高度差值不大于1，说明还是可以继续往上层递归，那么应该取左右两个子树较高的那个高度+1作为当前结点的高度。
        return abs(left_height - right_height) > 1 ? -1 : max(left_height, right_height) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};
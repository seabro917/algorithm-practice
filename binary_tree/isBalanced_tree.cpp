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
    // 这个函数这里其实还是用来求以输入结点为根节点的子树的高度（所以最后还是求了个左右子树的max）。
    // 唯一变化是这里我们用-1来标记当前遍历到的子树已经不满足对称二叉树性质，继续往上层遍历的时候只要遇到-1直接返回false即可（-1就是代表false）。
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
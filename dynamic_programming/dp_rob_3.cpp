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

//  leetcode 337
class Solution {
private:
    // 长度为2的数组，第一个元素代表不偷当前结点能偷到的最大值，第二个元素代表不偷当前结点可能偷到的最大值。
    vector<int> robTree(TreeNode* cur) {
        if (!cur) {
            return vector<int> {0, 0}; 
        }
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 不偷当前结点的情况，那么可以考虑偷当前结点的左右孩子结点，且分别考虑偷不偷左右孩子结点。
        int val_1 = max(left[0], left[1]) + max(right[0], right[1]);
        // 偷当前结点的情况，那么就不能偷当前结点的左右孩子，下面两个数组left和right第一个元素就代表的是不偷当前结点左孩子和右孩子，例，left[0]代表的是对于cur->left这个结点，不偷cur->left时可能偷到的最大值。
        int val_2 = cur->val + left[0] + right[0];
        return vector<int> {val_1, val_2};
    }
public:
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
};
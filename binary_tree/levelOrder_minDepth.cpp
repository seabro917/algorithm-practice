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

// leetcode 111
// 递归法
class Solution {
public:
    // 和求最大深度不同的地方在于这里根据最小深度的定义，如果一个结点左右孩子有一个为空，那么需要看它不为空的那一个子树，而不是直接返回0.
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && root->right) {
            return minDepth(root->right) + 1;
        }
        if (root->left && !root->right) {
            return minDepth(root->left) + 1;
        }
        else {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
    }
};

// 迭代法
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int res = 0;
        if (root != nullptr) {
            que.push(root);
        }
        while (!que.empty()) {
            int size = que.size();
            res++;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                if (cur->left) {
                    que.push(cur->left);
                }
                if (cur->right) {
                    que.push(cur->right);
                }
                if (cur->left == nullptr && cur->right == nullptr) {
                    return res;
                }
            }
        }
        return res;
    }
};
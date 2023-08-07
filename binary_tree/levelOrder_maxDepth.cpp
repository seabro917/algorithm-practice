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

// leetcode 104
// 递归写法
class Solution {
public:
    // 后续遍历从叶子结点往上依次传递结果。
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};


// 迭代写法
class Solution {
public:  
    int maxDepth(TreeNode* root) {
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
            }
        }
        return res;
    }
};
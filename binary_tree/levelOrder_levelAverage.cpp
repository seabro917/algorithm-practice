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
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> res;
        if (root != nullptr) {
            que.push(root);
        }
        while (!que.empty()) {
            double sum_temp = 0;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                sum_temp += cur->val;
                if (cur->left) {
                    que.push(cur->left);
                } 
                if (cur->right) {
                    que.push(cur->right);
                } 
            }
            // 一层遍历结束，取当前层平均。
            res.push_back(sum_temp / size);
        }
        return res;
    }
};
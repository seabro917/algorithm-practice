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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        vector<int> res;
        if (root != nullptr) {
            que.push(root);
        }
        while (!que.empty()) {
            int max_val = INT32_MIN;
            int size = que.size();
            for (int i = 0; i< size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                max_val = max(max_val, cur->val);
                if (cur->left) {
                    que.push(cur->left);
                }
                if (cur->right) {
                    que.push(cur->right);
                }
            }
            res.push_back(max_val);
        }
        return res;
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        que.push(root);
        while (!que.empty()) {
            vector<int> temp;
            int size = que.size();
            // 在这个for循环中queue的size不断改变（因为在for循环内不断pop出去还有push进来）
            // 所以在进入for循环前要记录一下当前这一层对应的queue的size，并且用在for循环的条件中，而不能直接用queue.size()作为for循环的条件。
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                temp.push_back(cur->val);
                // 要先判断接下来还有没有左右叶子结点。
                if (cur->left) {
                    que.push(cur->left);
                }
                if (cur->right) {
                    que.push(cur->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
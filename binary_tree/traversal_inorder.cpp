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


// 迭代版本
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // cur指针是用于遍历整个二叉树，记录当前遍历到的结点。
        TreeNode* cur = root;
        stack<TreeNode*> st;
        // 注意这里是或逻辑，只要有一个满足即可。
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                // 空了，说明当前左没有了，上一个不为空的结点（栈顶）应该为中间结点，按照左中右的顺序处理，应该将栈顶元素（中）加入结果数组。
                cur = st.top();
                res.push_back(cur->val);
                st.pop();
                cur = cur->right;     
            }
        }
        return res;
    }
};


// 递归版本
class Solution {
private:
    void traversal(TreeNode* node, vector<int>& res) {
        if (node == nullptr) {
            return;
        }
        traversal(node->left, res);
        res.push_back(node->val);
        traversal(node->right, res);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};
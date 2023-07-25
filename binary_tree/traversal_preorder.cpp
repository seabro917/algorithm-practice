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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        st.push(root);
        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            res.push_back(temp->val);
            if (temp->right != NULL) {
                st.push(temp->right);
            }
            if (temp->left != NULL) {
                st.push(temp->left);
            }      
        }
        return res;
    }
};


// 递归版本
class Solution {
private:
    void traversal(TreeNode* node, vector<int>& res) {
        if (node == NULL) {
            return;
        }
        res.push_back(node->val);
        traversal(node->left, res);
        traversal(node->right, res);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};
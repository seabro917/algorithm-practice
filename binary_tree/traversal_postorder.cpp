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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        // 先写一个中右左的遍历 --> 即在中左右的前序遍历的代码中调换左右的push
        st.push(root);
        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            res.push_back(temp->val);
            if (temp->left != NULL) {
                st.push(temp->left);
            }
            if (temp->right != NULL) {
                st.push(temp->right);
            }
        }
        // 上面得到了中右左的遍历结果，这里再对结果整体翻转一次即得到左右中的结果，即后续结果。
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
private:
    void traversal(TreeNode* node, vector<int>& res) {
        if (node == NULL) {
            return;
        }
        traversal(node->left, res);
        traversal(node->right, res);
        res.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};
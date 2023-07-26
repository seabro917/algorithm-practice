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

//  递归 深度优先
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

//  迭代 深度优先
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        if (root != nullptr) {
            st.push(root);
        }
        while (!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            swap(cur->left, cur->right);
            if (cur->right) {
                st.push(cur->right);
            }
            if (cur->left) {
                st.push(cur->left);
            }
        }
        return root;
    }
};

// 广度优先
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != nullptr) {
            que.push(root);
        }
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                swap(cur->left, cur->right);    
                if (cur->left) {
                    que.push(cur->left);
                }  
                if (cur->right) {
                    que.push(cur->right);
                }  
            }
        }
        return root;
    }
};
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

//  通过构建中序遍历数组
class Solution {
private: 
    // 中序遍历
    void inOrderTraversal(TreeNode* root, vector<int>& inOrder) {
        if (!root) {
            return;
        }
        inOrderTraversal(root->left, inOrder);
        inOrder.push_back(root->val);
        inOrderTraversal(root->right, inOrder);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> inOrder;
        inOrderTraversal(root, inOrder);
        if (inOrder.size() == 1) {
            return inOrder[0];
        }
        int res = INT32_MAX;
        for (int i = 1; i < inOrder.size(); i++) {
            res = min(res, inOrder[i] - inOrder[i-1]);
        }
        return res;
    }
};

// 递归遍历过程中直接算
class Solution {
private: 
    // 别放在递归函数里面了...
    int res = INT32_MAX;
    TreeNode* pre = nullptr;
    // 中序遍历
    void inOrderTraversal(TreeNode* root) {
        if (!root) {
            return;
        }
        inOrderTraversal(root->left);
        if (pre) {
            res = min(res, root->val - pre->val);
        }
        pre = root;
        inOrderTraversal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        inOrderTraversal(root);
        return res;
    }
};
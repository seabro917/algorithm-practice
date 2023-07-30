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

// leetcode 105
class Solution {
private:
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0) {
            return nullptr;
        }
        
        int root_val = preorder[0];
        TreeNode* root = new TreeNode(root_val);
        
        // 在中序遍历数组中找到分割点.
        int cuttingIndex = 0;
        for (; cuttingIndex < inorder.size(); cuttingIndex++) {
            if (inorder[cuttingIndex] == root->val) {
                break;
            }
        }

        // 分割中序遍历数组.
        vector<int> leftInorder(inorder.begin(), inorder.begin() + cuttingIndex);
        vector<int> rightInorder(inorder.begin() + cuttingIndex + 1, inorder.end());

        // 分割前序遍历数组.
        // 事实上cuttingIndex和leftInorder.size()的值是一样的,所以这里其实也可以写成:
        // vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + cuttingIndex + 1);
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + leftInorder.size() + 1);
        vector<int> rightPreorder(preorder.begin() + leftInorder.size() + 1, preorder.end());

        root->left = traversal(leftPreorder, leftInorder);
        root->right = traversal(rightPreorder, rightInorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        return traversal(preorder, inorder);
    }
};
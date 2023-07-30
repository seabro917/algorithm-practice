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

// leetcode 106
class Solution {
private:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        // 递归终止条件是后序遍历的数组为空，可以直接返回上层递归。
        if (postorder.size() == 0) {
            return nullptr;
        }
        // 后序遍历数组的最后一个元素一定为当前层根节点。
        int root_val = postorder[postorder.size() -1];
        TreeNode* root = new TreeNode(root_val);

        // 在中序遍历数组中寻找这个根节点，分割中序遍历数组。
        int cuttingIndex = 0;
        for (; cuttingIndex < inorder.size(); cuttingIndex++) {
            if (inorder[cuttingIndex] == root->val) {
                break;
            }
        }

        // 根据找到的结点，分割中序遍历数组。
        vector<int> leftInorder(inorder.begin(), inorder.begin() + cuttingIndex);
        // 注意范围，把中间的分割点踢出去。
        vector<int> rightInorder(inorder.begin() + cuttingIndex + 1, inorder.end());

        // 根据中序遍历数组的分割结果再回头来分割后序遍历数组,因为二者的左右分割长度一定是相等的.
        // 注意后续遍历数组的最后一个元素已经作为当前层根节点被使用了,所以分割的时候不可以再考虑它.
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // 注意范围，把中间的分割点踢出去。
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end() - 1);

        // 分割完毕,进入下一层递归.
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) {
            return nullptr;
        }
        return traversal(inorder, postorder);
    }
};
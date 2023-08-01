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

//  直接中序遍历一次,二叉搜索树的中序遍历一定是一个递增数组(不包括相等).
class Solution {
private:
    void inOrderTraversal(TreeNode* root, vector<int>& inOrder) {
        if (!root) {
            return;
        }
        inOrderTraversal(root->left, inOrder);
        inOrder.push_back(root->val);
        inOrderTraversal(root->right, inOrder);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> inOrder;
        inOrderTraversal(root, inOrder);
        if (inOrder.size() == 1) {
            return true;
        }
        int pre = inOrder[0];
        for (int i = 1; i < inOrder.size(); i++) {
            if (inOrder[i] <= pre) {
                return false;
            }
            pre = inOrder[i];
        }
        return true;
    }
};


// 递归 中序遍历
class Solution {
public:
    long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        bool left = isValidBST(root->left);

        // 除了分别判断当i前结点的左右子树之外，还要额外判断当前结点的值是否大于中序遍历的下一个结点。
        if (pre >= root->val) {
            return false;
        }
        pre = root->val;

        bool right = isValidBST(root->right);

        return left && right;
    }
};
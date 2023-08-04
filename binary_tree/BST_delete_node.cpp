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


// leetcode 450
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        // 找到了要删除的结点
        if (root->val == key) {
            // 如果要删除的结点是叶子结点,那么直接返回nullptr让上层接住即可.
            if (!root->left && !root->right) {
                return nullptr;
            }
            // 接下来两种情况都是一样的处理方式,如果要删除结点左右孩子有一个为空,另一个不为空,那么直接把不为空的那一个接上,返回给上一层即可.
            if (!root->left && root->right) {
                return root->right;
            }
            if (root->left && !root->right) {
                return root->left;
            }
            // 最后一种情况是要删除的结点左右都不为空,那么根据搜索二叉树的性质,把要删除结点的左子树全部接在右子树的最后一个左叶子结点的左边(一直向左遍历),并把右子树的根节点(要删除结点的右孩子)返回即可.
            else {
                TreeNode* cur = root->right;
                while (cur->left) {
                    cur = cur->left;
                }
                // while循环结束，cur指向root的右子树向左遍历的最后一个叶子结点。
                // 将root的整个左子树全都接在这个结点的左边，然后返回root的右孩子。
                cur->left = root->left;
                return root->right;
            }
        }
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};


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

// // 递归
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         // 判断是否为空的条件一定要放在第一个,否则当root为空的时候先判断root的val的话会报空指针错误.
//         if (root == nullptr || root->val == val) {
//             return root;
//         }
//         TreeNode* res = nullptr;
//         if (root->val > val) {
//             return searchBST(root->left, val);
//         }
//         if (root->val < val) {
//             return searchBST(root->right, val);
//         }
//         return res;
//     }
// };

// 迭代
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* res = nullptr;
        if (!root) {
            return res;
        }        
        while (root) {
            if (root->val > val) {
                root = root->left;
            }
            else if (root->val < val) {
                root = root->right;
            }
            else {
                return root;
            }
        }
        return res;
    }
};
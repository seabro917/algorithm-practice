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

// //  dfs
// class Solution {
// public:
//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//         if (!root1) {
//             return root2;
//         }
//         if (!root2) {
//             return root1;
//         }

//         // 剩下的逻辑就是两个根节点都不为空,直接执行单层操作逻辑两个相加即可.
//         root1->val += root2->val;

//         root1->left = mergeTrees(root1->left, root2->left);
//         root1->right = mergeTrees(root1->right, root2->right);
//         return root1;
//     }
// };

// bfs
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // 处理双根节点.
        queue<TreeNode*> que_1;
        queue<TreeNode*> que_2;
        if (!root1) {
            return root2;
        }
        if (!root2) {
            return root1;
        }
        // 剩下就是两个根节点都不为空的情况
        que_1.push(root1);
        que_2.push(root2);
        while (!que_1.empty() || !que_2.empty()) {
            TreeNode* temp_1 = que_1.front();
            TreeNode* temp_2 = que_2.front();
            que_1.pop();
            que_2.pop();

            temp_1->val += temp_2->val;

            if (temp_1->left && temp_2->left) {
                que_1.push(temp_1->left);
                que_2.push(temp_2->left);
            }
            if (temp_1->right && temp_2->right) {
                que_1.push(temp_1->right);
                que_2.push(temp_2->right);
            }
            if (!temp_1->left && temp_2->left) {
                temp_1->left = temp_2->left; 
                // que_2.push(temp_2->left);
            }
            if (!temp_1->right && temp_2->right) {
                temp_1->right = temp_2->right; 
                // que_2.push(temp_2->right);
            }
        }
        return root1;
    }
};


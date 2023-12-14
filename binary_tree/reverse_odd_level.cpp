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

//  leetcode 2415 
//  https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree/solutions/2565326/2415-fan-zhuan-er-cha-shu-de-qi-shu-ceng-9bjn/

// // dfs递归写法
// class Solution {
// private:
//     void dfs(TreeNode* left_node, TreeNode* right_node, int level) {
//         if (!left_node) {
//             return;
//         }
//         // 奇数层交换
//         if (level % 2) {
//             int val_1 = left_node->val, val_2 = right_node->val;
//             left_node->val = val_2;
//             right_node->val = val_1;
//         }
//         // 考虑对称性
//         dfs(left_node->left, right_node->right, level + 1);
//         dfs(left_node->right, right_node->left, level + 1);
//     }
// public:
//     TreeNode* reverseOddLevels(TreeNode* root) {
//         dfs(root->left, root->right, 1);
//         return root;
//     }
// };

// bfs层序遍历写法
class Solution {
private:
    void reverseVal(vector<TreeNode*> cur_level_nodes) {
        int left = 0, right = cur_level_nodes.size() - 1;
        while (left < right) {
            int val_1 = cur_level_nodes[left]->val, val_2 = cur_level_nodes[right]->val;
            cur_level_nodes[left]->val = val_2;
            cur_level_nodes[right]->val = val_1;
            left++;
            right--;
        }
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;
        while (!que.empty()) {
            vector<TreeNode*> cur_level_nodes;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = que.front();
                que.pop();
                cur_level_nodes.push_back(temp);
                if (temp->left) {
                    que.push(temp->left);
                }
                if (temp->right) {
                    que.push(temp->right);
                }
            }
            // 奇数层反转
            if (level % 2) {
                reverseVal(cur_level_nodes);
            }
            level++;
        }
        return root;
    }
};
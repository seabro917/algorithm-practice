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


// leetcode 654
class Solution {
private:
    //  前序遍历
    TreeNode* traversal(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }

        // 找到数组中最大元素及其下标.
        int max_val = INT32_MIN;
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max_val) {
                max_val = nums[i];
                maxIndex = i;
            }
        }

        // 以最大元素的值构建本层根节点.
        TreeNode* root = new TreeNode(max_val);

        // 分割下标左右数组,构建左右最大子树.
        vector<int> left_nums(nums.begin(), nums.begin() + maxIndex);
        // 和构建二叉树类似的,注意把分割点剔除.
        vector<int> right_nums(nums.begin() + maxIndex + 1, nums.end());
        
        // 构建左边最大子树
        root->left = traversal(left_nums);
        // 构建右边最大子树
        root->right = traversal(right_nums);
        
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        return traversal(nums);
    }
};
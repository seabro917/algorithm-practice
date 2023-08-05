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

// leetcode 108

// 一开始想着和构建普通二叉树一样递归函数里面用数组的端点构造新数组，看了题解才想到只要是涉及到有序的，每次取中间index的数值的，都应该马上想到二分法。
class Solution {
private: TreeNode* traversal(vector<int>& nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    TreeNode* cur = new TreeNode(0);
    int mid = (left + right) / 2;
    cur->val = nums[mid];
    // 用左右区间递归遍历根节点的左右子树。
    cur->left = traversal(nums, left, mid - 1);
    cur->right = traversal(nums, mid + 1, right);
    
    return cur;
}
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums, 0, nums.size() - 1);
    }
};
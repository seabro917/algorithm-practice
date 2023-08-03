/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// leetcode 235
// 用迭代法最容易理解，直接从根结点开始遍历（一定要从上往下遍历），这样遍历到的第一个在[p,q]（假设p<q）区间内的结点就是要返回的结点。
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            // 根据搜索二叉树的性质，这时候应该往左搜索。
            if (root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            // 同理，这时候应该往右搜索。
            // 注意这里是else if 与上面的判断是并列关系，只能取一个，不然的话上面判断执行完之后有可能这一行还会执行、
            else if (root->val < p->val && root->val < q->val) {
                root = root->right;
            }
            // 剩下的情况就是p和q在当前结点的两侧，那么从上往下遍历到的第一个满足这个条件的结点就是p和q的最近公共祖先.
            else {
                return root;
            }
        }
        return nullptr;
    }
};
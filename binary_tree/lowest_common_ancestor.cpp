/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//  leetcode 236
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/solutions/240096/236-er-cha-shu-de-zui-jin-gong-gong-zu-xian-hou-xu/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }
        if (root == p || root == q) {
            return root;
        }
// 上面这个一条判断其实涵盖了下面这种情况，比如p=5， q=6
//       1
//      / \
//     6   2
//    /\   /\
//   7  7 7  7
//     /\
//    5 11
// 从下往上递归到6的时候（root=6），left返回的是null，right返回的是5，所以返回5，即func(6那个结点)=5那个结点
// 再往上返回的时候，root=1，left=5（上一层返回来的），right=null，根据如果右空左不空返回左，返回左（6），即，func(1那个结点)=6那个结点，所以最后找到了6这个结点.



        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (!left && !right) {
            return nullptr;
        }
        if (!left && right) {
            return right;
        }
        if (left && !right) {
            return left;
        }
        return root;  // left和right都不为空的情况,说明p和q分别位于root左右两侧,root即为要返回的最近公共祖先.
    }
};
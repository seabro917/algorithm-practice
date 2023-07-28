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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_sum = sumOfLeftLeaves(root->left);
        // 在当前结点的结果等于他的左右子结点结果之和的基础上，如果当前结点他的左结点是一个左叶子，那么直接可以计算出结果了。
        if (root->left && !root->left->left && !root->left->right) {
            left_sum = root->left->val;
        }
        int right_sum = sumOfLeftLeaves(root->right);
        return left_sum + right_sum;
    }
};


    //     1
    //    / \
    //   7   2
    //  /    /\
    // 5    3  3
    //     /\  /\
    //    4  4 4 4
    
// 比如这里其实如果遍历到7这个结点的时候（root==7），执行到 int left_sum = sumOfLeftLeaves(root->left); 这一行的时候，进入到下一层递归，root==5，
// 其实又会进入到下一层递归，可以得到root==5这一层递归的返回值为0（因为5的左右均为空），所以在root==7这一层递归，运行到int left_sum = sumOfLeftLeaves(root->left);的时候
// left_sum = 0. 程序继续运行到下一行,这时候我们可以发现根据if判断,root->left(也就是5)会被判定成左叶子结点,于是本来值为0的left_sum会被更新成5.这就是这个解法中对于左叶子结点的特殊处理
//     ----> 先统一管理值,然后单独判断左叶子结点,更新值.

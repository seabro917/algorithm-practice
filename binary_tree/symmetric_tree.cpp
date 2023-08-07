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

// 递归法。
class Solution {
private:
    bool compare(TreeNode* left, TreeNode* right) {
        // 这里的递归是只比较当前层输入的left和right两个结点，不是考虑以left和right为根节点的两个数。
        // 所以只要两个都为空，那么就说明left和right这两个对应的结点对称，可以直接true。
        if (!left && !right) {
            return true;
        }
        else if (!left || !right || left->val != right->val) {
            return false;
        }
        bool cmp_outside = compare(left->left, right->right);
        bool cmp_inside = compare(left->right, right->left);
        return cmp_outside && cmp_inside;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return compare(root->left, root->right);
    }
};


//  队列的迭代法。
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == nullptr) {
            return true;
        }
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()) {
            // 两个两个成对取出，左的左和右的右，左的右和右的左。
            TreeNode* left_temp = que.front();
            que.pop();
            TreeNode* right_temp = que.front();
            que.pop();
            // 这里是continue而不是直接true，因为只是对前这一对都为空，其他的对应的结点值还没有比较。
            if (left_temp == nullptr && right_temp == nullptr) {
                continue;
            }      
            // 一旦出现本应对应的结点为空没对上或者对应结点的值不相等，那么直接就可以false掉。
            else if (!left_temp || !right_temp || left_temp->val != right_temp->val) {
                return false;
            }
            // 压入队列的时候要保证对应。
            // 这里有一个点要注意，之前的用队列遍历的情况这里都要判断不为空才push到队列内，这一题不用判断是因为我们之后要判断是否对应结点有空，所以先不管它是不是空，我们都先放到队列内。
            que.push(left_temp->left);
            que.push(right_temp->right);
            que.push(left_temp->right);
            que.push(right_temp->left);
        }
        return true;
    }
};
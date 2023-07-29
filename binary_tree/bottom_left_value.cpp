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

//  DFS递归
class Solution {
private:
    int max_depth = INT32_MIN;
    int res = 0;
    // 前序遍历。
    void traversal(TreeNode* root, int depth) {
        if (root == nullptr) {
            return;
        }
        // 左边永远是比右边先被遍历到，所以只要遇到了深度更深的，直接赋值就可以。
        // 同层左边结点经过if判断之后，max_depth的值就已经被更新了，那么再回到上一层递归的时候右边结点就不会再进入if判断了。
        if (depth > max_depth) {
            res = root->val;
            max_depth = depth;
        }
        traversal(root->left, depth + 1);
        traversal(root->right, depth + 1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return res;   
    }
};


    //       1
    //      / \
    //     7   2
    //    /\   /\
    //   5  8 3  3
    //  /\
    // 10 11

// 比如这里，当运行到5那个结点的时候，depth = max_depth = 2， 运行到traversal(root->left, depth + 1);这一行，depth + 1为3，进入下一层递归。
// 到10这个结点，此时depth为3，max_depth为2，进入if判断，更新max_depth的值为3，同时更新res，这样再进入下一层递归，因为10左右均为空，直接return。
// 于是又返回到以5为根节点这一层的递归,此时注意,max_depth已经由于遍历过10这个结点而更新成了3,但是运行到下一行traversal(root->right, depth + 1);的时候,depth依旧是2
// 即depth+1为3,所以右节点11不会进入if判断 ----> 正是因为是先遍历左边后遍历右边.




//  BFS层序遍历
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        int res = 0;
        if (root != nullptr) {
            que.push(root);
        }
        while (!que.empty()) {
            int size = que.size();
            res = que.front()->val;
            for (int i = 0; i < size; i++) {
                TreeNode* temp = que.front();
                que.pop();
                if (temp->left) {
                    que.push(temp->left);
                }
                if (temp->right) {
                    que.push(temp->right);
                }
            }
        }
        return res;
    }
};
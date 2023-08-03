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

//  leetcode 701
// 想的简单一点就是，只要遍历到一个符合的叶子结点，然后根据搜索二叉树的性质将这个新的结点接在最后即可。
// 注意在遍历过程中也要考虑到二叉搜索树的性质,保证基于要新加入的结点的值,每一步遍历都要符合二叉搜索树的性质.

// 递归法,有返回值.
class Solution {
private:
    TreeNode* traversal(TreeNode* root, int val) {
        // 这里直接构建最后一个新加入的结点,把它返回到上一层,在上一层根据搜索二叉树的性质把这个返回值接住.
        if (!root) {
            return new TreeNode(val);
        }
        if (root->val > val) {
            root->left = traversal(root->left, val);
        }
        else {
            root->right = traversal(root->right, val);
        }
        return root;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) { 
        if (!root) {
            return new TreeNode(val);
        } 
        return traversal(root, val);
    }
};


// 递归法,无返回值.
class Solution {
private:
    TreeNode* pre = nullptr;
    void traversal(TreeNode* root, int val) {
        // 空结点了,说明上一个结点是要找的叶子结点,所以要看新加入的结点数值和pre的数值比较,在pre尾部接上新加入的结点.
        if (!root) {
            if (pre->val > val) {
                pre->left = new TreeNode(val);
            }
            else {
                pre->right = new TreeNode(val);
            }
            // 虽然函数是无返回值,但是这里return不能省,递归函数的终止条件内return不可以省略.
            return;
        }
        pre = root;
        if (root->val > val) {
            traversal(root->left, val);
        }
        else {
            traversal(root->right, val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) { 
        if (!root) {
            return new TreeNode(val);
        } 
        traversal(root, val);
        return root;
    }
};



// 迭代法,感觉二叉搜索树都是迭代法好理解一点,毕竟直接从上到下遍历有性质可用.
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {  
        // 先保存一下根节点.   
        TreeNode* res = root;
        TreeNode* pre = nullptr;
        if (!root) {
            return new TreeNode(val);
        }
        while (root) {
            // 先保存一下上一个结点,方便遍历到最后叶子结点下一个null的时候,用上一个结点把新的结点接在尾部.
            pre = root;
            if (root->val > val) {
                root = root->left;
            }
            else if (root->val < val) {
                root = root->right;
            }
        }
        // 此时while循环结束,root是空指针,pre指向的是我们要找的叶子节点,将新加入的结点按照二叉搜索树的性质接在pre后面.
        if (pre->val > val) {
            pre->left = new TreeNode(val);
        }
        else {
            pre->right = new TreeNode(val);
        }
        return res;
    }
};
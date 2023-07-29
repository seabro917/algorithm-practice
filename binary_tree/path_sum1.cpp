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
private: 
    // 直接原地求和+判断.
    bool backtracking(TreeNode* root, int& sum, int targetSum) {
        // 到达叶子结点，判断是否当前路径是否满足条件。
        // 满足要求的和的话直接return true就行了，不满足的话要记得return false到上一层，继续寻找下一条路径。
        if (root->left == nullptr && root->right == nullptr) {
            sum += root->val;
            if (sum == targetSum) {
                return true;
            }
            // 当前路径不满足条件
            return false;
        }
        // 单层处理逻辑，将当前结点的值放入path中。
        sum += root->val;
        if (root->left) {
            if(backtracking(root->left, sum, targetSum)){
                return true;
            }
            else{
                sum -= root->left->val;
            }
        }
        if (root->right) {
            if(backtracking(root->right, sum, targetSum)){
                return true;
            }
            else{
                sum -= root->right->val;
            }
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        if (root == nullptr) {
            return false;
        }
        return backtracking(root, sum ,targetSum);
    }
};




class Solution {
private: 
    // 记录所有路径的回溯。
    void backtracking(TreeNode* root, vector<vector<int>>& paths, vector<int>& path) {
        if (root->left == nullptr && root->right == nullptr) {
            path.push_back(root->val);
            paths.push_back(path);
            return;
        }
        // 单层处理逻辑，将当前结点的值放入path中。
        path.push_back(root->val);
        if (root->left) {
            backtracking(root->left, paths, path);
            path.pop_back();
        }
        if (root->right) {
            backtracking(root->right, paths, path);
            path.pop_back();
        }
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        if (root == nullptr) {
            return false;
        }
        backtracking(root, paths, path);
        for (int i = 0; i < paths.size(); i++) {
            if (accumulate(paths[i].begin(), paths[i].end(), 0) == targetSum) {
                return true;
            }
        }
        return false;
    }
};
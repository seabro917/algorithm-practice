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
// leetcode 501
//  直接在递归中使用map统计出现频率,可用于任意二叉树.
class Solution {
private: 
    void inOrderTraversal(TreeNode* root, unordered_map<int, int>& map) {
        if (root == nullptr) {
            return;
        }
        inOrderTraversal(root->left, map);
        map[root->val]++;
        inOrderTraversal(root->right, map);
    }

    bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;
        vector<int> res;
        inOrderTraversal(root, map);
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), cmp);
        res.push_back(vec[0].first);
        // 继续寻找是否有出现频率相同的众数.
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].second == vec[0].second) {
                res.push_back(vec[i].first);
            }
        }
        return res;
    }
};


//  针对搜索二叉树的中序遍历处理.
class Solution {
private: 
    TreeNode* pre = nullptr;
    int count = 0;
    int maxCount = 0;
    void inOrderTraversal(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        inOrderTraversal(root->left, res);
        // 如果pre为空说明遍历到了整个树一个中序遍历的结点.
        if (!pre) {
            count = 1;
        }
        // 当前结点的数值和上一个结点相同,count加一.
        else if (pre->val == root->val) {
            count++;
        }
        // 当前结点和上一个结点数值不相等,说明遍历到了一个值全新的结点,重置计数.
        else {
            count = 1;
        }
        pre = root;
        // 可能的众数,先不管它会不会比当前的众数更nb,先放进去再说.
        if (count == maxCount) {
            res.push_back(root->val);
        }
        // 比当前众数更nb了,那么之前结果集里面的都可以舍弃掉了---->主打的就是一个喜新厌旧
        if (count > maxCount) {
            // 一定要清空,一是为了喜新厌旧,二是为了防止相同的众数被多次放入.
            res.clear();
            res.push_back(root->val);
            maxCount = count;
        }
        inOrderTraversal(root->right, res);
    }

    bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        inOrderTraversal(root, res);
        return res;
    }
};
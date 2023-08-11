// leetcode 96
// https://leetcode.cn/problems/unique-binary-search-trees/solutions/6693/hua-jie-suan-fa-96-bu-tong-de-er-cha-sou-suo-shu-b/
// 二叉搜索树的左子树和右子树一定都还是二叉搜索树
// 1-5和6-10这两种情况最多能构造出的不同的二叉搜索树的数量是一样的，因为二叉搜索树考虑的是数值的相对大小关系，而不是具体大小。
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j <= i; j++) {
                // 遍历j，j代表当前的根节点，左子树有j-1个数字，所以左子树有dp[j - 1]种不同的二叉搜索树
                // 右子树有i-j个数字，所以右子树有dp[i - j]种不同的二叉搜索树。
                // 这样当前的这个以j为根节点的情况就一共有dp[j - 1] * dp[i - j]种不同的二叉搜索树。
                dp[i] += dp[j - 1] * dp[i - j];  
            }
        }
    return dp[n];
    }
};
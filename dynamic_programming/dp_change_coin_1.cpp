// leetcode 322

// 完全背包
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 这里要注意的是因为递推公式里面是求的min，为了保证递推能进行，需要把所有元素初始化为max
        vector<int> dp(amount + 1, INT32_MAX);
        // 求方法数目一般初始化为1，其他的一般初始化为0.
        dp[0] = 0;
        // 这题不是求方法数目，所以内外遍历顺序无所谓
        // 但是因为是完全背包，所以应该还是正向遍历.
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]]  != INT32_MAX) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        return dp[amount] == INT32_MAX ? -1 : dp[amount];
    }
};
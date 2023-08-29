// leetcode 188

// 实际就是股票3的一个比较general的情况，找到规律即可。
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2*k + 1, 0));
        // 初始化
        for (int i = 0; i < k; i++) {
            dp[0][2*i + 1] = -prices[0];
            dp[0][2*i] = 0;
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < k; j++) {
                dp[i][2*j + 1] = max(dp[i - 1][2*j + 1], dp[i - 1][2*j] - prices[i]);
                dp[i][2*j + 2] = max(dp[i - 1][2*j + 2], dp[i - 1][2*j + 1] + prices[i]); 
            }
        }
        return dp[prices.size() - 1][2*k];
    }
};
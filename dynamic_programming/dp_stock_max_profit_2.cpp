// leetcode 122
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            // 这一行是和之前只能买卖股票一次的情况唯一不一样的地方
            // 因为这一题可以买卖多次,那么买的时候可能之前几天累计下来已经有一定的利润了
            // 而之前全程只能买卖一次的那题，只要买了，那么说明肯定只买了这一次，即之前肯定没有累计利润。
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]); 
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
    }
};
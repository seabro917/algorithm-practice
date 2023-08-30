// leetcode 309

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/1897179/mai-mai-gu-piao-xi-lie-by-my_mel-mz32/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 0是持有股票的状态，1是不持有股票的状态。
        vector<vector<int>> dp(prices.size(), vector<int> (2, 0));
        if (prices.size() == 1) {
            return 0;
        }
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[1][0] = max(-prices[0], -prices[1]);
        dp[1][1] = max(0, prices[1] - prices[0]);
        for (int i = 2; i < prices.size(); i++) {
            // 当前天状态为不持有股票时无所谓，不受有没有冷冻期的影响
            // 但是当前天状态为持有股票的时候，会受到冷冻期这一限制的影响，例，当前天有股票，前天也有，昨天没有，那么这就不符合冷冻期的限制，但是当前天没有股票的时候找不到这种反例，所以不受冷冻期的限制影响，转移函数还是和之前几题一样。
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][1]);
    }
};


// 主要不同处就在于，当一天的状态为不持有股票的时候，那么是不是今天卖的，根据这个多划分一个状态即可。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 0是持有股票的状态，1是不持有股票，且这一天不持有股票是因为今天卖了股票，2是不持有股票，但是不是今天卖的。
        vector<vector<int>> dp(prices.size(), vector<int> (3, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 1; i < prices.size(); i++) {
            // 今天持有股票的话，那么一定不是前一天卖出的，不然今天会处于冷冻期(即一定不可能是状态1)，那么要么是昨天就已经持有股票，要么是今天买的股票且昨天不持有股票且不是昨天卖的(状态2)
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            // 今天不持有股票且今天卖出，那么昨天一定有股票
            dp[i][1] = dp[i - 1][0] + prices[i];
            // 今天没有股票，且不是今天卖出，那么要么是昨天卖出的要么昨天没卖出
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
    }
};
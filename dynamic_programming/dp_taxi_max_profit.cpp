// leetcode 2008
// 动态规划
// 从位置n - 1到位置n,实际差距就是在考虑接不接终点为位置n的乘客,如果不接那么就是dp[n] = dp[n - 1]
// 接终点为n的旅客的话,就要考虑接哪个终点为n的旅客才能是利益最大化(好多终点为n的,看选择哪个)
// 对于普遍性的一名终点为n的旅客,假设他的起点为x,那么我们如果要载他的话就一定要保证在x位置的时候位置是空的
// dp[n] = dp[x] + (n - x + 小费)
class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long> dp(n + 1, 0);
        // 储存以每个位置为终点的乘客信息,pair存储的信息为{起点, 小费}
        // summary[n]是一个vector,对应的是终点为n的所有的乘客的pair信息
        vector<vector<pair<int, int>>> summary(n + 1);
        // 将summary的信息填满
        for (int i = 0; i < rides.size(); i++) {
            // 当前乘客的起点和小费
            pair<int, int> cur_info = {rides[i][0], rides[i][2]};
            // 当前乘客的终点是rides[1],存入对应的summary
            summary[rides[i][1]].push_back(cur_info);
        }
        // 计算dp数组
        for (int i = 1; i <= n; i++) {
            // 不承载终点为位置i的乘客的情况,那么dp[i] = dp[i - 1]
            dp[i] = dp[i - 1];
            // 承载终点为位置i的乘客的情况,那么就要看看在所有终点为位置n的乘客中,搭载哪个可以得到的利润最大
            for (int j = 0; j < summary[i].size(); j++) {
                // summary[i][j].first代表的就是第j个终点位置为i的乘客他的起点位置
                // i - summary[i][j].first + summary[i][j].second 代表终点减起点加消费,即利润
                dp[i] = max(dp[i], dp[summary[i][j].first] + i - summary[i][j].first + summary[i][j].second);
            }
        }
        return dp[n];
    }
};
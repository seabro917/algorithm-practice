// leetcode 2830
// 动态规划,和2008一样一样的,除了计算利润的时候只有一项
// 就考虑接不接单要买第n个房子的顾客
// 相比于2008那题,这题要注意下标
// 这一题下标从0开始,dp[1]对应只有标号为0的一座房子的情况,dp[n]对应下标为n-1一共n座房子的情况
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n + 1, 0);   
        vector<vector<pair<int, int>>> summary(n + 1);
        for (int i = 0; i < offers.size(); i++) {
            pair<int, int> cur_info = {offers[i][0], offers[i][2]};
            summary[offers[i][1]].push_back(cur_info);
        }
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i];
            for (int j = 0; j < summary[i].size(); j++) {
                dp[i + 1] = max(dp[i + 1], dp[summary[i][j].first] + summary[i][j].second);
            }
        }
        // for (auto c : dp) {
        //     cout << c << endl; 
        // }
        return dp[n];
    }
};
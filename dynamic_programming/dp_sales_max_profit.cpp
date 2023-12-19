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


// 仿照leetcode 1235的该问题普遍写法
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int size = offers.size();
        vector<int> dp(size + 1);
        // 按照结束下标(其实就是结束时间)升序排序
        sort(offers.begin(), offers.end(), [&](vector<int>& a, vector<int>& b) -> bool {return a[1] < b[1];});
        for (int i = 0; i < size; i++) {
            // 不考虑第i个offer(也就是不管第i个工作)和只考虑第i个offer的情况
            dp[i + 1] = max(dp[i], offers[i][2]);
            // 最接近第i个offer的前一个offer
            // 相比leetcode 1235,这里求到的upperbound的边界要-1(offers[i][0] - 1),这是因为本题中一个结束了不能马上同时开始,必须要在下一个时间点开始
            int j = upper_bound(offers.begin(), offers.begin() + i, offers[i][0] - 1, [&](int x, auto& offer) -> bool {return x < offer[1];}) - offers.begin();
            dp[i + 1] = max(dp[i + 1], dp[j] + offers[i][2]);
        }
        return dp[size];
    }
};
// leetcode 1235
// https://leetcode.cn/problems/maximum-profit-in-job-scheduling/solutions/1913143/by-ac_oier-rgup/
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<int> dp(n + 1);
        // 之前选择两个最好的工作还有售卖房子还有出租车那几题用了pair,里面只放了结束时间和利益
        // 这里需要重新构造整个的info,然后再排序,所以要把所有信息都放进去
        vector<tuple<int, int, int>> info;
        for (int i = 0; i < n; i++) {
            info.emplace_back(startTime[i], endTime[i], profit[i]);
        }
        // 老规矩,按照结束时间升序排序
        sort(info.begin(), info.end(), [&](auto& a, auto& b) -> bool {return get<1>(a) < get<1>(b);});
        // 开始递推
        for (int i = 0; i < n; i++) {
            // tuple的解包
            auto [cur_st, cur_et, cur_pf] = info[i];
            // 不选择当前工作和只选择当前这一个工作的情况
            dp[i + 1] = max(dp[i], cur_pf);
            // 排序之后的info里面最后一个(最接近工作i)在工作i之前能完成的工作
            int j = upper_bound(info.begin(), info.begin() + i, cur_st, [&](int x, auto& job) -> bool {return x < get<1>(job);}) - info.begin();
            // 选择当前工作i,并且也考虑工作i之前最近的那个下标的工作的情况
            dp[i + 1]= max(dp[i + 1], dp[j] + cur_pf);
        }
        return dp[n];
    }
};


// class Solution {
// public:
//     int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
//         int n = profit.size();
//         vector<tuple<int, int, int>> jobs(n);
//         for (int i = 0; i < n; ++i) jobs[i] = {endTime[i], startTime[i], profit[i]};
//         sort(jobs.begin(), jobs.end());
//         vector<int> dp(n + 1);
//         for (int i = 0; i < n; ++i) {
//             auto [_, s, p] = jobs[i];
//             int j = upper_bound(jobs.begin(), jobs.begin() + i, s, [&](int x, auto& job) -> bool { return x < get<0>(job); }) - jobs.begin();
//             dp[i + 1] = max(dp[i], dp[j] + p);
//         }
//         return dp[n];
//     }
// };
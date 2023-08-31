// leetcode 300

// 难得官方题解写得还不错...
// 注意dp数组的含义是当前下标的元素一定被选中
// 在计算dp[i]之前，dp[0]到dp[i - 1]都已经被计算完了，那么
// dp[i] = max(dp[j] + 1) \forall j \in [0, i - 1]
// https://leetcode.cn/problems/longest-increasing-subsequence/solutions/147667/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        for (auto c : dp) {
            cout << c << endl;
        }
        return result;
    }
};
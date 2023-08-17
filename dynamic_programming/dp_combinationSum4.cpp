// leetcode 377

//完全背包 求排列的方法数
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 1; j <= target; j++) {
            // 求排列 先遍历重量再遍历物品
            for (int i = 0; i < nums.size(); i++) {
                if (j - nums[i] >= 0 && dp[j] < INT_MAX - dp[j - nums[i]]) {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};

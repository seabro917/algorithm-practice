// leetcode 198
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            // 实际就是考虑，当我们遍历到当前这个下标i了,当前下标的前一个和前两个偷还是不偷
            // 1. 偷第i个,那么说明第i-1个一定没有偷,那么dp[i - 1] = dp[i - 2], dp[i]就是dp[i-2]再加上第i个房屋的价值
            // 2. 不偷第i个,那么dp[i]其实和dp[i - 1]就是一样的了
            // 上面这两种情况取最大的即可.
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};
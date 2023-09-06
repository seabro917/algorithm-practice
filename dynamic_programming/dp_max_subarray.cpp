// leetcode 53
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i]代表的是nums数组从0到下标为i的位置的子数组，以i结尾的最大的连续子数组的和
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            // 要么就是直接在上一个子数组之后接上nums当前下标的值，要么就是只算nums当前下标的值
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > res) {
                res = dp[i];
            }
        }
        return res;
    }
};
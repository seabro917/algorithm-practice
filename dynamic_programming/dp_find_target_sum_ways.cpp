// leetcode 494
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (abs(target) > sum) {
            return 0;
        }
        // 这是因为bagSize = (target + sum) / 2 一定为一个正整数，如果不是那么肯定不存在解
        if ((target + sum) % 2) {
            return 0;
        }    
        int bagSize = (target + sum) / 2;
        vector<int> dp(bagSize + 1,0);
        dp[0] = 1;
        // 剩下的要求的就是有几种办法能让这个bagSize塞满
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};
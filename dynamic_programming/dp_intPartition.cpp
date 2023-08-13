// leetcode 416
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<int> dp(10001, 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        // 如果原输入数组的元素总和为奇数，那么肯定不可能拆分。
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        // 这一题里面nums[i]既是物品的重量，也是物品的价值.
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target) {
            return true;
        }
        return false;
    }
};
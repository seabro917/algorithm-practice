// leetcode 674
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // dp[i]代表的是，考虑从下标为0到下标为i的范围内，以下标为i的元素为结尾的符合条件的最长连续递增子序列的长度，所以最小一定为1(符合条件的子序列仅包含i位置这个元素)，所以dp数组全都初始化为1.
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            // 取所有里面最大的，因为对于输入数组而言，符合条件的子序列出现的时候并不一定是以最后一个元素为结尾。
            if (dp[i] > res) {
                res = dp[i];
            }
        }
        return res;
    }
};
// leetcode 213

// 成环之后其实就是在原先的基础上多考虑了一步
// 即：第一件房子和最后一间房子肯定不可以同时偷，那么就分类讨论这两种情况，取最大的。
class Solution {
private:
    int rob_helper(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }
        // 这样初始化之后其实dp数组第一个或者最后一个会为0不被更新，但是算是省了麻烦。
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[end];
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        // 第一间房子确定不偷的情况
        int case_1 = rob_helper(nums, 1, nums.size() - 1);
        // 最后一间房子确定不偷的情况
        int case_2 = rob_helper(nums, 0, nums.size() - 2);
        return max(case_1, case_2);
    }
};
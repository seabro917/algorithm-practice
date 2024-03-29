// leetcode 1049
// 其实和分割等和子集那题一样，那一题是看dp[target]是否和target相等，这题同样是将数组分割成两个子集，使得两个子集的和的差最小。
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(16000, 0);
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }
        int target = sum / 2;
        for (int i = 0; i < stones.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        // 一个子集的和为dp[target]，另一个为sum - dp[target]。
        // “在计算target的时候，target = sum / 2 因为是向下取整，所以sum - dp[target] 一定是大于等于dp[target]的。”
        return sum - dp[target] - dp[target];
    }
};
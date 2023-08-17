// leetcode 518

// 完全背包 装满背包容量为amount的方法的组合总数
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        // 一般这种求组合的都是初始化为1，因为如果初始化为0的话根据递推公式dp数组所有元素都会为0.
        dp[0] = 1;
        // 求组合是先遍历物品，再遍历重量
        for (int i = 0; i < coins.size(); i++) {
            // 完全背包内循环也是正向遍历.
            for (int j = 0; j <= amount; j++) {
                if (j >= coins[i]) {
                    dp[j] += dp[j - coins[i]]; 
                }
            }
        }
        return dp[amount];
    }
};
// leetcode 343
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        // 其实只要思想就是当前要拆分的数到底是把它拆成两个还是拆分成两个以上
        // 两个以上的话具体拆成几个我不知道，但是可以借助之前已经算好的dp数组
        // 遍历一个j，拆成两个的话那么i就拆成j和(i-j)
        // 拆成三个的话,那么就是拆成j和dp[i-j]
        // 每来一个j就取一次他们两种情况的最大值,遍历完所有j之后最大的就是结果
        //     ---->所以求最大值的时候还要一起比较dp[i],即当前的最大值.
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i - j]));
            }
        }
        return dp[n];
    }
};
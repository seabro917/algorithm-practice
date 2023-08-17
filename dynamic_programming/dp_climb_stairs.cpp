// leetcode 70
class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) {
            return n;
        }
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};


// 完全背包解法
// 实际就是求装满容量为n的方法的排列
// 物品为每次可以爬的楼梯数目,这里就是2,可以设置为更多,比如一次最多可以爬3层或者4层...
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        int m = 2;
        for (int j = 1; j <= n; j++) {
            for (int i = 0; i <= m; i++) {
                if (j >= i) {
                    dp[j] += dp[j - i];
                }
            }
        }
        return dp[n];
    }
};



// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n < 3) {
//             return n;
//         }
//         else {
//             return climbStairs(n - 2) + climbStairs(n - 1); 
//         }
//     }
// };
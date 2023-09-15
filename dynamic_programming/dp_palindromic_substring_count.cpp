// leetcode 647
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;
        // 注意遍历顺序，可以根据状态转移函数推出来遍历顺序
        for (int i = s.size() - 1; i >= 0; i--) {
            // j肯定比i大，所以内循环的j从i开始
            for (int j = i; j < s.size(); j++) {
                // 只有当两边的两个字符相等的时候才有可能构成回文子串.
                if (s[i] == s[j]) {
                    // "a"或者"aa"的情况
                    if (j - i <= 1) {
                        res++;
                        dp[i][j] = true;
                    }
                    else if (dp[i + 1][j - 1]) {
                        res++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return res;
    }
};
// leetcode 516
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        // 初始化，单个字符一定他本身就是长度为1的回文串
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            // 同样的，j一定比i要大
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    // 用i位置的字符不用j位置的字符或者用j位置的字符不用i位置的字符
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};
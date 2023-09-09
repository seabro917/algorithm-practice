// leetcode 392

// 实际就是先找到两个字符串的公共子序列长度，只要这个长度等于要判断的s字符串的长度，那么说明s字符串全部都是s和t的公共子序列，即s是t的子序列。
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) {
            return true;
        }
        if (s.size() != 0 && t.size() == 0) {
            return false;
        }
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), 0));
        // 初始化dp数组的第一行和第一列，分别拿一个数组的第一个元素和另一个数组的每个位置的元素进行比较。
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[0]) {
                dp[i][0] = 1;
            }
            else if (s[i] != t[0] && i >= 1) {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int j = 0; j < t.size(); j++) {
            if (s[0] == t[j]) {
                dp[0][j] = 1;
            }
            else if (s[0] != t[j] && j >= 1) {
                dp[0][j] = dp[0][j - 1];
            }
        }
        for (int i = 1; i < s.size(); i++) {
            for (int j = 1; j < t.size(); j++) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;  
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        if (dp[s.size() - 1][t.size() - 1] == s.size()) {
            return true;
        }
        return false;
    }
};
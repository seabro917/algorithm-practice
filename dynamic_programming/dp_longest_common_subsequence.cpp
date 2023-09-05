// leetcode 1143
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
        // 初始化dp数组的第一行和第一列，分别拿一个数组的第一个元素和另一个数组的每个位置的元素进行比较。
        for (int i = 0; i < text1.size(); i++) {
            if (text1[i] == text2[0]) {
                dp[i][0] = 1;
            }
            else if (text1[i] != text2[0] && i >= 1) {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int j = 0; j < text2.size(); j++) {
            if (text1[0] == text2[j]) {
                dp[0][j] = 1;
            }
            else if (text1[0] != text2[j] && j >= 1) {
                dp[0][j] = dp[0][j - 1];
            }
        }
        for (int i = 1; i < text1.size(); i++) {
            for (int j = 1; j < text2.size(); j++) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;  
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size() - 1][text2.size() - 1];
    }
};
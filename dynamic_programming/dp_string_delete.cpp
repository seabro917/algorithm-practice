// leetcode 583

// 妥协了 还是直接dp数组初始化比size大1吧 要不然实在不好初始化
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++ ) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); j++ ) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int temp = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    dp[i][j] = min(temp, dp[i - 1][j - 1] + 2);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
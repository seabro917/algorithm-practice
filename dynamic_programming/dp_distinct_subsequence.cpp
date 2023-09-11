// leetcode 115
// 同样是考虑当下标移动的时候,当前下标的两个字符串对应的字符是否相等.
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned long long>> dp(s.size(), vector<unsigned long long>(t.size(), 0));
        // 初始化dp数组 
        // 只考虑遍历s就行了(只考虑t[0]是否和s当前下标的字符相等即可),因为t的子串如果比s的子串还长,那么根本就不用比了.
        dp[0][0] = s[0] == t[0] ? 1:0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == t[0]) {
                dp[i][0] = dp[i - 1][0] + 1;
            }
            else {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int i = 1; i < s.size(); i++) {
            for (int j = 1; j < t.size(); j++) {
                if (s[i] == t[j]) {
                    // 当遍历到的s子串和t子串的当前位置字符相等的时候,有两种情况.
                    // 1.我们用了s串的子串的当前的这个字符,那么既然用了,那么为了保证当前这个t的子串全都在s当前这个子串中出现,那么一定有s[i]正好和t[j]匹配到一起,那么其实有没有他们就无所谓了(你们两个自己秀恩爱去吧)那么这种情况下的结果其实就是dp[i - 1][j - 1]
                    // 2.没用到s当前子串的当前这个字符,但是我们还是要保证t当前这个子串在s子串中出现啊,那么就是dp[i - 1][j](这种情况下的时候其实就是考虑了dp[i - 1][j] = dp[i][j],因为我都知道你s[i]这个字符肯定没被用到了,那么有你没你没区别)
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    // 如果s[i]和t[j]不相等,那么其实就是上面相等的时候的第二种情况,我们无论如何都要保证t的当前子串出现在s子串中,那么既然我知道s[i]和t[j]不相等了,那么其实就是说明这时候s[i]一定没用到(即上面s[i]和t[j]相等时的第二种情况).
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        for (auto c: dp) {
            for (auto d: c) {
               cout << d << ",";
            }
            cout << endl;
        }
        return dp[s.size() - 1][t.size() - 1];
    }
};
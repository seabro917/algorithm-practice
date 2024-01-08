// leetcode 2707
// https://leetcode.cn/problems/extra-characters-in-a-string/solutions/2590667/zi-fu-chuan-zhong-de-e-wai-zi-fu-by-leet-f0lu/
// 下标真恶心啊...
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size() + 1, 0);
        unordered_set<string> my_set;
        for (auto c : dictionary) {
            my_set.insert(c);
        }
        // dp[0] = 0;
        // 考虑新加入的这一个字符s[i]是否可以新构成一个以s[i]为结尾且在dictionary里的单词
        // 如果不可以那递推公式就是dp[i + 1] = dp[i] + 1 (新加的这一个单独的字符s[i])
        // 如果可以的话,就要看看找到的单词有多长,根据长度看看考虑之前哪个dp数组的值
        for (int i = 1; i <= s.size(); i++) {
            dp[i] = dp[i - 1] + 1;
            for (int j = i - 1; j >= 0; j--) {
                if (my_set.contains(s.substr(j, i - j))) {
                    dp[i] = min(dp[i], dp[j]);     
                }
            }
        } 
        return dp[s.size()];
    }
};
// leetcode 2719
// https://leetcode.cn/problems/count-of-integers/solutions/2296043/shu-wei-dp-tong-yong-mo-ban-pythonjavacg-9tuc/
class Solution {
    const int MOD = 1e9 + 7;
public:
    int calculate(string s, int min_sum, int max_sum) {
        // 总的状态数目为s.length() * (9 * s.length()),第二维度的大小是每个位置都填9最大可能得到的和 
        vector<vector<int>> dp(s.length(), vector<int>(9 * s.length(), -1));
        // lambda函数
        function<int(int, int, bool)> dfs = [&](int i, int sum, bool is_limit) -> int {
            if (sum > max_sum) {
                return 0;
            }
            if (i == s.length()) {
                return sum >= min_sum ? 1 : 0;
            }
            // 如果当前位置的值在之前递归中已经被记忆化记录过,则直接返回
            // 只考虑is_limit为false的情况以避免dp冲突
            // dp[i][sum] != -1 表示当前位置的dp数组的值在递归中已经被计算过
            if (!is_limit && dp[i][sum] != -1) {
                return dp[i][sum];
            }
            // 和模板一样的处理方式,如果i位置之前都还一直是limit,那么当前位置的上界受限
            int upperBound = is_limit ? s[i] - '0' : 9;
            int res = 0;
            // 枚举填入当前位的数字并且递归进行到下一位
            for (int j = 0; j <= upperBound; j++) {
                res = (res + dfs(i + 1, sum + j, is_limit && (j == upperBound))) % MOD;
            }
            // 记忆化记录,同样的,只记录is_limit为false的情况以避免dp冲突
            if (!is_limit) {
                dp[i][sum] = res;
            }
            return res;
        }; 
        return dfs(0, 0, true);
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int res = calculate(num2, min_sum, max_sum) - calculate(num1, min_sum, max_sum) + MOD;
        // 单独判断num1这个数字本身是否符合
        int sum_num1 = 0;
        for (auto c : num1) {
            sum_num1 += c - '0';
        }
        if (sum_num1 <= max_sum && sum_num1 >= min_sum) {
            res++;
        }
        return res % MOD;
    }
};
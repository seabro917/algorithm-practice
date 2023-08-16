// leetcode 474
class Solution {
private:
    vector<int> calZeorsOnes(string s) {
        vector<int> res(2, 0);
        for (int i = 0; i < s.length(); i++) {
            res[s[i] - '0']++;
        }
        return res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1 , 0)));
        // 遍历物品，在这题就是数组的每个字符串.
        // 注意这里是从1开始，而不是0，虽然下标是从0开始，但是考虑的是具体代表的物理意义.
        // 而且联想一下dp数组的初始化，01背包问题直接初始化为0，所以可以直接开始迭代.
        for (int i = 1; i <= strs.size(); i++) {
            vector<int> zeroOnes_temp = calZeorsOnes(strs[i - 1]);
            // 遍历重量，在这题就是要求不超过多少个0和1.
            // 这里是考虑整体的，没有考虑滚动数组，所以前序遍历.
            // 遍历0
            for (int j = 0; j <= m; j++) {
                // 遍历1
                for (int k = 0; k <= n; k++) {
                    if (j - zeroOnes_temp[0] < 0 || k - zeroOnes_temp[1] < 0) {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                    else {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - zeroOnes_temp[0]][k - zeroOnes_temp[1]] + 1);
                    }
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};


// 滚动数组
class Solution {
private:
    vector<int> calZeorsOnes(string s) {
        vector<int> res(2, 0);
        for (int i = 0; i < s.length(); i++) {
            res[s[i] - '0']++;
        }
        return res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1 , 0));
        // 遍历物品，在这题就是数组的每个字符串.
        // 注意这里是从1开始，而不是0，虽然下标是从0开始，但是考虑的是具体代表的物理意义.
        // 而且联想一下dp数组的初始化，01背包问题直接初始化为0，所以可以直接开始迭代.
        for (int i = 1; i <= strs.size(); i++) {
            vector<int> zeroOnes_temp = calZeorsOnes(strs[i - 1]);
            // 遍历重量，在这题就是要求不超过多少个0和1.
            // 这里是考虑滚动数组，所以要后续遍历.
            // 遍历0
            for (int j = m; j >= zeroOnes_temp[0]; j--) {
                // 遍历1
                for (int k = n; k >= zeroOnes_temp[1]; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zeroOnes_temp[0]][k - zeroOnes_temp[1]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};


// 关于为什么在滚动数组的情况下遍历重量需要后续遍历：
// 首先用滚动数组的想法就是把上一层的数据copy到当前层，因为从普通01背包二维dp的递推公式可以看出来，当前遍历到的位置的值只取决于该位置左上方向的值。
// 当我们把上一层的数据copy到当前层，如果前序遍历的话，那么根据地推公式可以看出来我们本想用的上层的值就已经被遍历当前层时覆盖掉了。
// [a, a, a, a, c, b, b, b, b] ---> c代表是滚动数组种当前遍历到的位置，其实实际上就是：后序遍历时，c右边的值都是当前层的（他们都是基于上层的值来更新出来的）。
// 而c左边的值还没有边遍历到,即,他们还是上一层的值,根据之前的分析,我们是需要维护这些上层的值来更新当前层当前位置的值.
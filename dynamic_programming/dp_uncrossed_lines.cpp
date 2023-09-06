// leetcode 1035

// 和两个字符串最长公共子序列那题一模一样
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        // 初始化dp数组的第一行和第一列，分别拿一个数组的第一个元素和另一个数组的每个位置的元素进行比较。
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == nums2[0]) {
                dp[i][0] = 1;
            }
            else if (nums1[i] != nums2[0] && i >= 1) {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int j = 0; j < nums2.size(); j++) {
            if (nums1[0] == nums2[j]) {
                dp[0][j] = 1;
            }
            else if (nums1[0] != nums2[j] && j >= 1) {
                dp[0][j] = dp[0][j - 1];
            }
        }
        for (int i = 1; i < nums1.size(); i++) {
            for (int j = 1; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;  
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[nums1.size() - 1][nums2.size() - 1];
    }
};
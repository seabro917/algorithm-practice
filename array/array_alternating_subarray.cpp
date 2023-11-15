// leetcode 2760
// 滑动窗口
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int res = 0;
        // 和之前几个做过的滑动窗口不一样的是这里是遍历左端点，然后移动右端点。
        // 因为这里要找的是最长的，而不是最短的，最短的一般都是收缩，这里是依次增长
        for (int left = 0; left < nums.size(); left++) {
            if (nums[left] % 2 == 0 && nums[left] <= threshold) {
                // 左端点符合条件了，那么至少结果为1
                int temp_res = 1;
                int right = left + 1;
                // 符合条件，右端点依次移动     
                while (right < nums.size() && nums[right] % 2 != nums[right - 1] % 2 && nums[right] <= threshold) {
                    temp_res = right - left + 1;
                    right++;
                }
                res = max(res, temp_res);
            }
        }
        return res;
    }
};
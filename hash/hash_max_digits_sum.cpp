// leetcode 2342
// https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/solutions/1687010/by-huaqq-054u/
// 键值对里面键代表的数位和，值代表的是原数组里面符合这个数位和的 最 大 元素值
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int res = -1;
        unordered_map<int, int> my_map;
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            // 计算当前元素数位和
            int digits_sum = 0;
            while (temp > 0) {
                digits_sum += temp % 10;
                temp /= 10;
            }
            if (my_map[digits_sum]) {
                res = max(res, nums[i] + my_map[digits_sum]);
            }
            // 更新符合当前这个数位和的原数组元素的最大值
            my_map[digits_sum] = max(my_map[digits_sum], nums[i]);
        }
        return res;
    }
};
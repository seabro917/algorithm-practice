// leetcode 34
// 二分,两次二分分别找第一次出现的位置和第二次出现的位置,注意两种情况收缩端点的情况.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int left_bound = -1;
        int right_bound = -1;
        vector<int> res;
        // 找第一个等于目标数字的位置index
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            // 相等的情况下,往左边收缩,因为要找第一个等于目标数字的位置
            else {
                left_bound = mid;
                right = mid - 1;
            }
        }
        left = 0;
        right = nums.size() - 1;
        // 找最后一个等于目标数字位置的index
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            // 相等的情况下,往右边收缩,因为要找最后一个等于目标数字的位置
            else {
                right_bound = mid;
                left = mid + 1;
            }
        }
        res.push_back(left_bound);
        res.push_back(right_bound);
        return res;
    }
};
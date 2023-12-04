// leetcode 33
// 每次分都会分出来一个有序,一个无序数组
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            // left到mid是有序数组
            if (nums[left] <= nums[mid]) {
                // target是否在有序数组部分,决定应该如何收缩边界
                target >= nums[left] && target <= nums[mid] ? right = mid - 1 : left = mid + 1;
            }
            // mid到right是有序数组
            else {
                // target是否在有序数组部分,决定应该如何收缩边界
                target >= nums[mid] && target <= nums[right] ? left = mid + 1 : right = mid - 1;
            }
        }
        return -1;
    }
};
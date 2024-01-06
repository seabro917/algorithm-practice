// leetcode 153
// 二分,对旋转数组每次二分必定分出一个有序一个无序的,在无序的那一组里面继续找
// 好像之前做到过类似的
class Solution {
public:
    int findMin(vector<int>& nums) {
        int right = nums.size() - 1, left = 0; 
        int res = INT32_MAX;
        while (right >= left) {
            int mid = left + (right - left) / 2;
            cout << "left: " << left << endl;
            cout << "right: " << right << endl;
            cout << "mid: " << mid << endl;
            // 左边那一组是无序的情况
            if (nums[mid] < nums[left]) {
                res = min(res, nums[mid]);
                right = mid - 1;
            }
            // 右边一组是无序的情况
            else {
                res = min(res, nums[left]);
                left = mid + 1;
            }   
        }
        return res;
    }
};
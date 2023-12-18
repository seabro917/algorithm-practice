// leetcode 162
// 处理边界值的匿名函数真的很巧妙啊...
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        auto getItem = [&](int idx) -> pair<int, int> {
            // 边界值默认是最小的,pair内第一个数字设置成0,这样和其他非边界值进行比较的时候直接判断小于
            if (idx == -1 || idx == size) {
                return {0, 0};
            }
            return {1, nums[idx]};
        };
        int left = 0, right = size - 1, res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (getItem(mid) > getItem(mid - 1) && getItem(mid) > getItem(mid + 1)) {
                return mid;
            }
            else if (getItem(mid) < getItem(mid + 1)) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};
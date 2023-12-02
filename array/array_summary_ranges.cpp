// leetcode 228
// 区间,分组循环.
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int left = 0;
        while (left < nums.size()) {
            int right = left; 
            // 这里要判断右端点是小于size - 1,因为第二个判断里面有right + 1
            while (right < nums.size() - 1 && nums[right + 1] == nums[right] + 1) {
                right++;
            }
            if (left == right) {
                res.push_back(to_string(nums[left]));
            }
            else {
                res.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
            }
            left = right + 1;
        }
        return res;
    }
};
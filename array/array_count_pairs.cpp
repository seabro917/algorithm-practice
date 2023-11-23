// leetcode 2824
// https://cplusplus.com/reference/algorithm/lower_bound/
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            int k = lower_bound(nums.begin(), nums.begin() + i, target - nums[i]) - nums.begin();
            res += k;
        }
        return res;
    }
};
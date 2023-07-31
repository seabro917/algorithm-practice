// leetcode 724
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (total - sum - nums[i] == sum) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};
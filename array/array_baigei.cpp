// leetcode 2656
// 什么白给题...
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(), nums.end());
        return ( (2*start + k - 1) * k / 2);
    }
};
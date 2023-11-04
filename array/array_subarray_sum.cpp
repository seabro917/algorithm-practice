// leetcode 560
// https://leetcode.cn/problems/subarray-sum-equals-k/solutions/238572/he-wei-kde-zi-shu-zu-by-leetcode-solution/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> my_map;
        int res = 0;
        int sum = 0;
        my_map[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (my_map.find(sum - k) != my_map.end()) {
                res += my_map[sum - k];
            }
            // 这一行不能在if之前，否则会没考虑到vector只有一个元素的情况
            my_map[sum]++;
        }
        return res;
    }
};


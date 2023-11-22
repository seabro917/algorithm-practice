// leetcode 26
// 快慢双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        if (nums.size() == 1) {
            return 1;
        }
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[slow] == nums[fast]) {
                continue;
            }
            else {
                slow++;
                nums[slow] = nums[fast]; 
            }
        }
        return slow + 1;
    }
};
// leetcode 169
// “同归于尽”
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == majority) {
                count++;
            } 
            else if (count == 0) {
                majority = nums[i];
                count = 1;
            }
            else{
                count--;
            }
        }
        return majority;
    }
};
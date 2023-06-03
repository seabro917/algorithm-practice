class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow_ptr = 0;
        for(int fast_ptr = 0 ; fast_ptr < nums.size() ; fast_ptr++){
            if(nums[fast_ptr] != val){
                nums[slow_ptr] = nums[fast_ptr];
                slow_ptr++;
            }
        }
        return slow_ptr;
    }
};
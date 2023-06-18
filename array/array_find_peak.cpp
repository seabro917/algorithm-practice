class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int findPeakElement(vector<int>& nums) {
        // write code here
        if(nums.size() == 1){
            return 0;
        }
        // 直接单独判断端点吧，懒得想了...
        if(nums[0] > nums[1]){
            return 0;
        }
        if(nums[nums.size()-1] > nums[nums.size()-2]){
            return nums.size()-1;
        }   
        for(int ptr = 1 ; ptr < nums.size()-1 ; ptr++){
            if(nums[ptr] > nums[ptr - 1] && nums[ptr] > nums[ptr + 1]){
                return ptr;
            }
        }
        return 0;
    }
};

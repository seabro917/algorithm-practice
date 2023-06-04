class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int k = nums.size()-1;
        for(int left = 0, right = nums.size()-1 ; left <= right ;){
            if(nums[right] * nums[right] <= nums[left] * nums[left]){
                // 注意一定要先从最后放结果，因为双指针是判断较大的那个数。
                result[k] = nums[left] * nums[left];
                k--;
                left++;
            }
            else{
                result[k] = nums[right] * nums[right];
                k--;
                right--;
            }
        }
        return result;
    }
};
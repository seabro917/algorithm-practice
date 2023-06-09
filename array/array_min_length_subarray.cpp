class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int sum = 0;
        int result = INT32_MAX;
        // 滑动窗口 for循环遍历的是窗口的终止位置 而不是起始位置 --> 想一下那个动态滑动窗口的过程，先依次增加终止位置，然后再移动起始位置。
        for(int end = 0 ; end < nums.size() ; end++){
            sum += nums[end];
            while(sum >= target){
                // 如果当前窗口内的和大于等于目标，则移动起始位置，看看减小窗口能不能满足条件，因为需要找的是最小子数列。
                int res_temp = end - start + 1;
                if(res_temp < result){
                    result = res_temp;
                }
                sum -= nums[start];
                start++;
            }
        }
        if(result == INT32_MAX){
            return 0;
        }
        else{
            return result;
        } 
    }
};
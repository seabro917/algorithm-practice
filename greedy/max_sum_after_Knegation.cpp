#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < 0 && k > 0){
                nums[i] = -nums[i];
                k--;
            }
        }
        // 再排序一次，这是为了如果上一步的结果k还有冗余，即上一步之后的结果数组全为正数。
        // 如果上一步得到的数组全为正数，且剩余k为偶数，那么不用继续了，因为直接对随意一个两次反转即可，结果不变。
        // 如果k是奇数，那么反转最小的一个正数即可。
        sort(nums.begin(), nums.end());
        if (k > 0 && k % 2 == 1){
            nums[0] = -nums[0];
        }

        for (int num: nums){
            res += num;
        }
        return res;
    }
};
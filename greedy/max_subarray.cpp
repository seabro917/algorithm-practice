#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT32_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if (sum > res){
                res = sum;
            }
            if (sum < 0){
                sum = 0;
            }
        }
        return res;
    }
};
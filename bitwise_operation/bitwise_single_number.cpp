// leetcode 136
// 异或操作符合交换律...真nb...
// https://labuladong.github.io/algo/di-san-zha-24031/shu-xue-yu-659f1/chang-yong-13a76/
// A ^ 0 = A, A ^ A = 0.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0; 
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};
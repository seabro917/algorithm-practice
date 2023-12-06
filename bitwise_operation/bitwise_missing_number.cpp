// leetcode 268
// 又是异或
// https://labuladong.github.io/algo/di-san-zha-24031/shu-xue-yu-659f1/chang-yong-13a76/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 先和最后一个数字异或一下,然后循环内res ^= i之后就是保证每个数字都被异或过了
        // 然后res ^= nums[i]全部执行完会少一次,少的那个数字就是最后结果
        // --> 其他数字都被异或了两次直接抵消为0
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};
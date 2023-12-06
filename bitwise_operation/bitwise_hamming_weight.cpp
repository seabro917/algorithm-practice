// leetcode 191
// https://labuladong.github.io/algo/di-san-zha-24031/shu-xue-yu-659f1/chang-yong-13a76/
// A & (A - 1) 的作用是将A的最低位的1变为0
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            n &= (n - 1);
            res++;
        }
        return res;  
    }
};
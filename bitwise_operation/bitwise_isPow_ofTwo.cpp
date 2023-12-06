// leetcode 231
// 位运算 A & (A - 1)作用是将A二进制表达的最后一个1变成0
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        return (n & (n - 1)) == 0;
    }
};
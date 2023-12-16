// leetcode 389
// 位运算,和只出现一次的数字那题一样,还是异或自身得到0
class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (char c : s) {
            res ^= c;
        }
        for (char c : t) {
            res ^= c;
        }
        return res;
    }
};
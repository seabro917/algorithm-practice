// leetcodev12
// https://leetcode.cn/problems/integer-to-roman/solutions/774611/zheng-shu-zhuan-luo-ma-shu-zi-by-leetcod-75rs/?envType=study-plan-v2&envId=top-interview-150
// 贪心 枚举出所有的可能,先考虑把大的用了,用到不能再用了再接着用下一个第二大的可能...
// 有点像喂饼干那个贪心
class Solution {
private:
    // 已排序保证从大到小，这样从前向后遍历的时候保证贪心优先用大的数字
    vector<string> patterns{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    vector<int> values{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
public:
    string intToRoman(int num) {
        string res;
        // 贪心，优先用大的数字对应的pattern
        for (int i = 0; i < patterns.size(); i++) {
            // num剩余的数字比当前遍历到的这个pattern代表的数字要大的话就一直用这个pattern灌满，直到不能再灌
            while (num >= values[i]) {
                res += patterns[i];
                num -= values[i];
            }
        }
        return res;
    }
};
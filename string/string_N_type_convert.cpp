// leetcode 6
// https://leetcode.cn/problems/zigzag-conversion/solutions/21610/zzi-xing-bian-huan-by-jyd/?envType=study-plan-v2&envId=top-interview-150
// 每天都在大佬的题解面前滑轨(流汗黄豆.jpg)
// 每一行构造一个string
// 触底或者到达第一行的时候反转flag,使得遍历方向反转
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> data(numRows);
        int current_line = 0;
        int flag = -1;
        for (char c : s) {
            data[current_line].push_back(c);
            // 首行或者尾行,反转flag使得遍历方向反转
            if (current_line == 0 || current_line == numRows - 1) {
                flag = - flag;
            }
            // 遍历行,根据flag的值决定是向下遍历还是向上遍历
            current_line += flag;
        }
        string res;
        for (string temp : data) {
            res += temp;
        }
        return res;
    }
};
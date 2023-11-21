// leetcode 13
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> my_map;
        my_map['I'] = 1;
        my_map['V'] = 5;
        my_map['X'] = 10;
        my_map['L'] = 50;
        my_map['C'] = 100;
        my_map['D'] = 500;
        my_map['M'] = 1000;
        // 从左到右遍历原字符串,如果遇到当前字母代表的数字比下一个字母代表的数字要小的情况则减去,否则执行加法.
        int res = 0;
        if (s.size() == 1) {
            return my_map[s[0]];
        }
        for (int i = 0; i < s.size() - 1; i++) {
            if (my_map[s[i]] < my_map[s[i + 1]]) {
                res -= my_map[s[i]];
            } 
            else {
                res += my_map[s[i]];
            }
        }
        // 最后还要把最后一位数字加上去
        res += my_map[s[s.size() - 1]];
        return res;
    }
};
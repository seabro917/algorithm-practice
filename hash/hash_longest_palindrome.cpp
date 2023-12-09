// leetcode 409
// 为什么tmd一共52个字母要用size为128的数组啊？？？
//  ----> 哦,想当然了...谁告诉你ASCII码中大写字母和小写字母是靠在一起的...
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128, 0);
        int res = 0;
        bool odd_already = false;
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'A']++;
        }
        for (int i = 0; i < 128; i++) {
            // cout << i << endl;
            // 偶数情况直接加入,因为偶数个都可以构成回文串
            if (count[i] % 2 == 0) {
                res += count[i];
            }
            // 我们可以容忍一个奇数存在,即构成的回文串的最中间一位,但是能且只能容忍一位
            else if (count[i] % 2 == 1 && !odd_already) {
                res += count[i];
                odd_already = true; 
            }
            else if (count[i] % 2 == 1 && odd_already) {
                res += count[i] - 1;
            }
        }
        return res;
    }
};


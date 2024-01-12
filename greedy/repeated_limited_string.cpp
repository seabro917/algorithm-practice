// leetcode 2182
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> charFrequency(26, 0);
        string res;
        for (auto c : s) {
            charFrequency[c - 'a']++;
        }
        int curCount = 0;
        for (int i = 25, j = 24; i >= 0 && j >= 0; ) {
            // 当前字符已用完
            if (charFrequency[i] == 0) {
                i--;
                curCount = 0;
            }
            else if (curCount < repeatLimit) {
                res += 'a' + i;
                charFrequency[i]--;
                curCount++;
            }
            else if (i > j && charFrequency[j] != 0) {
                curCount = 0;
                res += 'a' + j;
                charFrequency[j]--;
            }   
            else {
                j--;
            }
        }
        return res;
    }
};
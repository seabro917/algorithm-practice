// leetcode 14
// 直接暴力吧...
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = strs.size();
        int length = strs[0].size();
        for (int index = 0; index < length; index++) {
            char cur_char = strs[0][index];
            // cout << cur_char << endl;
            for (int j = 0; j < count; j++) {
                if (strs[j][index] != cur_char) {
                    return strs[0].substr(0, index);
                }
            }
        }
        return strs[0];
    }
};
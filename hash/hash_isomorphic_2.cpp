// leetcode 290
// 哈希
// 和isomorphic那个一样
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charTostr;
        unordered_map<string, char> strTochar;
        int index = 0;
        // 把截取s字符串中每个单词的操作放在了遍历pattern字符串的while循环内
        for (char c : pattern) {
            int j = index;
            // pattern中字符数大于s字符串中单词数目的情况
            if (j > s.size()) {
                return false;
            }
            // 获得s字符串中的一个单词
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            string current_word = s.substr(index, j - index);
            if ((charTostr.count(c) && charTostr[c] != current_word) || (strTochar.count(current_word) && strTochar[current_word] != c)) {
                return false;
            }
            // 移动index,定位到下一个单词的第一个字母
            index = j + 1;
            // cout << index << endl;
            charTostr[c] = current_word;
            strTochar[current_word] = c;
        }
        // s中单词数目大于pattern中字符数的情况
        return index < s.size() ? false : true;
    }
};
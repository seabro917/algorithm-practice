// leetcode 1657
// https://leetcode.cn/problems/determine-if-two-strings-are-close/solutions/2377025/gong-shui-san-xie-jian-dan-mo-ni-ti-by-a-feae/
// 1. 字符集相同,如果一个字符只在word1或者word2里面出现而没在另一个里面出现,那么肯定两字符串不接近
// 2. 对字符出现频率计数并且sort之后,逐项检查均相等
// 针对第二点,是对字符频率计数并且排序之后相等,所以相等的时候不一定对应的字符要一样e.g,
// s1: cabbba s2: abbccc
// 对字符出现频率计数并且sort之后,s1: 3(b) 2(a) 1(c)  s2: 3(c) 2(b) 1(a) 虽然对应的字符不一样,但是这个也是成立的情况
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // 记录每个字符出现的频率
        vector<int> count_1(26, 0), count_2(26, 0);
        for (char c: word1) {
            count_1[c - 'a']++;
        } 
        for (char c: word2) {
            count_2[c - 'a']++;
        } 
        // 检测是否字符集相同
        for (int i = 0; i < 26; i++) {
            if ((count_1[i] && !count_2[i]) || (!count_1[i] && count_2[i])) {
                return false;
            }
        }
        // 检测排序之后字符频率是否相等
        sort(count_1.begin(), count_1.end());
        sort(count_2.begin(), count_2.end());
        for (int i = 0; i < 26; i++) {
            if (count_1[i] != count_2[i]) {
                return false;
            }
        }
        return true;
    } 
};
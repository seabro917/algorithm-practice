#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

// 和anagram的思路一模一样.
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for (int i = 0; i < magazine.size(); i++) {
            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            record[ransomNote[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] < 0) {
                // record数组如果有的元素小于0，说明magazine中的字符肯定不足以支撑去构成ransomnote中所有的字符（大于0没有问题，说明有字符冗余）。
                return false;
            }
        }
        return true;
    }
};
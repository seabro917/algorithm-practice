// leetcode 58
// 反序遍历，第一次遇到空格的话就一直接着往前走，遇到非空格则开始计数
// 第二次遇到空格的时候说明此时最后一个单词长度已经计数完毕，直接break
// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         bool hasItem = false;
//         int count = 0;
//         for (int i = s.size() - 1; i >= 0; i--) {
//             if (s[i] == ' ') {
//                 if (hasItem) {
//                     break;
//                 }
//                 continue;
//             }
//             else {
//                 hasItem = true;
//                 count++;
//             }
//         } 
//         return count;
//     }
// };


// 没这么麻烦...直接先把空格去除完，然后开始计数就行...
class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size() - 1;
        while (s[index] == ' ') {
            index--;
        }
        // 末尾的空格去除完毕，开始记录单词的长度
        int count = 0;
        while (index >= 0 && s[index] != ' ') {
            count++;
            index--;
        }
        return count;
    }
};
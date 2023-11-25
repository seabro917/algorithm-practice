// leetcode 205
// 哈希
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 存两个字符串内字符的对应关系
        unordered_map<char, char> sTot;
        unordered_map<char, char> tTos;
        for (int i = 0; i < s.size(); i++) {
            char current_s = s[i];
            char current_t = t[i];
            if ((sTot.count(current_s) && sTot[current_s] != current_t) || (tTos.count(current_t) && tTos[current_t] != current_s)) {
                return false;
            }
            sTot[current_s] = current_t;
            tTos[current_t] = current_s; 
        }
        return true;
    }
};
// leetcode 49
// 和之前写过的几道判断是否可以用相同字符构成不同单词的题目一样
// 将单词的每个字母出现次数的counts的vector作为map的key，然后对应value就是一个string的vector。
// 遍历整个输入字符串vector，每次遇到相同的就直接在对应的value里进行push_back加到后面去
class Solution {
private: 
    vector<int> countLetters(string str) {
        vector<int> counts = vector<int>(26, 0);
        for (int i = 0; i < str.size(); i++) {
            counts[str[i] - 'a']++;
        }
        return counts;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> my_map;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++) {
            my_map[countLetters(strs[i])].push_back(strs[i]);
        }

        for (map<vector<int>, vector<string>>::iterator it = my_map.begin(); it != my_map.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
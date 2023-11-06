// leetcode 187
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> my_map;
        if (s.size() < 10) {
            return res;
        }
        for (int i = 0; i <= s.size() - 10; i++) {
            my_map[s.substr(i, 10)]++;
        }
        for (unordered_map<string, int>::iterator it = my_map.begin(); it != my_map.end(); it++) {
            cout << it->first << endl;
            if (it->second > 1) {
                res.push_back(it->first);
            }
        }
        return res;
    }
};
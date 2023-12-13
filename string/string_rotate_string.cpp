// leetcode 796
// 好好好,easy题用kmp咯 
class Solution {
private:
    void getNext (vector<int>& next, string& goal) {
        next[0] = 0;
        int j = 0;
        for (int i = 1; i < goal.size(); i++) {
            while (j - 1 >= 0 && goal[i] != goal[j]) {
                j = next[j -1];
            }
            if (goal[i] == goal[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    

public:
    bool rotateString(string s, string goal) {
        vector<int> next(goal.size());
        string double_s = s + s;
        if (s.size() != goal.size()) {
            return false;
        }
        getNext(next, goal);
        int j = 0;
        for (int i = 0; i < double_s.size(); i++) {
            while (j - 1 >= 0 && double_s[i] != goal[j]) {
                j = next[j - 1];
            }
            if (double_s[i] == goal[j]) {
                j++;
            }
            if (j == goal.size()) {
                return true;
            }
        }
        return false;
    }
};
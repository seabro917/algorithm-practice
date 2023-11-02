// leetcode 3
// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> my_set;
        int left = 0;
        int res = 0; 
        for (int right = 0; right < s.size(); right++) {
            // 一直弹出第一个元素，直到满足条件
            while (my_set.find(s[right]) != my_set.end()) {
                my_set.erase(s[left]);
                left++;
            }
            res = max(res, right - left + 1);
            my_set.insert(s[right]);
        }
        return res;
    }
};
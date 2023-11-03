// leetcode 438
// 滑动窗口
// https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/1125936/gong-shui-san-xie-shuang-zhi-zhen-shi-xi-t5hc/?envType=study-plan-v2&envId=top-100-liked
class Solution {
private: 
    bool checkEqual(vector<int> v1, vector<int> v2) {
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> need(26, 0);
        vector<int> have(26, 0);
        vector<int> res;
        int left = 0;
        for (int i = 0; i < p.size(); i++) {
            need[p[i] - 'a']++;
        }
        // cout << "test" << endl;
        for (int right = 0; right < s.size(); right++) {
            have[s[right] - 'a']++;
            // 收缩左边端点的情况
            while (right - left + 1 > p.size()) {
                have[s[left] - 'a']--;
                left++;
            }
            if (checkEqual(need, have)) {
                res.push_back(left);
            }
        }
        return res;
    }
};
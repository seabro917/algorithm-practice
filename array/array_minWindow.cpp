// // leetcode 76
// // 滑动窗口+字符串
// class Solution {
// private:
//     bool match(unordered_map<char, int> have, unordered_map<char, int> need) {
//         int num_match = 0;
//         for (auto it : need) {
//             if (have[it.first] < need[it.first]) {
//                 return false;
//             }
//         }
//         return true;
//     }
// public:
//     string minWindow(string s, string t) {
//         string res;
//         int start_point = 0;
//         int sub_length = INT32_MAX;
//         unordered_map<char, int> have;
//         unordered_map<char, int> need;
//         int left = 0;
//         for (char c : t) {
//             need[c]++;
//         }
//         for (int right = 0; right < s.size(); right++) {
//             have[s[right]]++;
//             while (left < right) {  
//                 have[s[left]]--;
//                 left++;
//                 // 删掉不删掉左边不影响，继续删。
//                 if (match(have, need)) {
//                     continue;
//                 }
//                 // 删掉了需要的字符，回溯。
//                 else {
//                     left--;
//                     have[s[left]]++;
//                     break;
//                 }
//             }
//             if (match(have, need)) {
//                 string temp = s.substr(left, right - left + 1);
//                 // 更新结果
//                 if (temp.size() < sub_length) {
//                     sub_length = temp.size();
//                     res = temp;
//                 }
//             }
//         }
//         return sub_length == INT32_MAX ? "" : res;
//     }
// };




// // leetcode 76
// // 滑动窗口+字符串
// class Solution {
// private:
//     bool match(unordered_map<char, int> have, unordered_map<char, int> need) {
//         int num_match = 0;
//         for (auto it : need) {
//             if (have[it.first] < need[it.first]) {
//                 return false;
//             }
//         }
//         return true;
//     }
// public:
//     string minWindow(string s, string t) {
//         string res;
//         int start_point = 0;
//         int end_point = 0;
//         int sub_length = INT32_MAX;
//         unordered_map<char, int> have;
//         unordered_map<char, int> need;
//         int left = 0;
//         for (char c : t) {
//             need[c]++;
//         }
//         for (int right = 0; right < s.size(); right++) {
//             have[s[right]]++;
//             while (match(have, need) && left <= right) { 
//                 string temp = s.substr(left, right - left + 1);
//                 // 更新结果
//                 if (temp.size() < sub_length) {
//                     sub_length = temp.size();
//                     res = temp;
//                 } 
//                 have[s[left]]--;
//                 left++;
//             }
//         }
//         return sub_length == INT32_MAX ? "" : res;
//     }
// };



// leetcode 76
// 滑动窗口+字符串
// 优化的点主要有两个，一是用一个单数组来扮演map的作用，和之前赎金信那个思维一样，这样每次调用match函数的时候就不需要一次次map查找了。第二个是substr函数不要放在循环里，循环里只记录和更新下标，最后只调用一次substr即可。
class Solution {
private:
    bool match(vector<int> map) {
        for (int i : map) {
            if (i > 0) {
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int start_point = 0;
        int end_point = INT32_MAX;
        int sub_length = INT32_MAX;
        vector<int> map = vector<int>(100, 0);
        int left = 0;
        for (char c : t) {
            map[c - 'A']++;
        }
        for (int right = 0; right < s.size(); right++) {
            map[s[right] - 'A']--;
            while (match(map)) { 
                // 更新结果
                if (right - left + 1 < sub_length) {
                    sub_length = right - left + 1;
                    start_point = left;
                    end_point = right;
                } 
                map[s[left] - 'A']++;
                left++;
            }
        }
        return sub_length == INT32_MAX ? "" : s.substr(start_point, end_point - start_point + 1);
    }
};
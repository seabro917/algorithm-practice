// leetcode 219
// 哈希
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> my_map;
        for (int i = 0; i < nums.size(); i++) {
            // map里面保存每个值出现的index,每次只要比较back也就是最后一位和当前index的差值即可.
            if (my_map[nums[i]].size() != 0 && i - my_map[nums[i]].back() <= k) {
                return true;
            }
            my_map[nums[i]].push_back(i);
        }
        return false;
    }
};


// 滑动窗口
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> my_set;
        // 维护一个长度为k+1的窗口-->窗口长度不变
        for (int i = 0; i < nums.size(); i++) {
            // 相当于窗口要右移,将最先加入的数据移出窗口
            if (i > k) {
                my_set.erase(nums[i - k - 1]);
            }
            // 判断新加入的元素在set内出现过没,因为窗口长度一直是k,那么只要set内有相等的数字,那么二者index差距一定小于等于k
            if (my_set.count(nums[i])) {
                return true;
            }
            // 否则将这个元素加入set,继续遍历
            my_set.insert(nums[i]);
        }
        return false;
    }
};
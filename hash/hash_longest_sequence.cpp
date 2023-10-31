// leetcode 128
// 把元素全都放到set里，遍历原vector，每次查看当前元素加一是否在set里存在。
// cnm超时了
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> my_set(nums.begin(), nums.end());
        int res = 1;
        if (nums.size() == 0) {
            return 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            // 要做一步剪枝，因为循环中包括了重复不需要的操作
            // 如果当前元素减一在set中出现了，那么可以直接跳过了，因为之前肯定已经走过这个了，而且肯定比你长
            if (my_set.find(nums[i] - 1) != my_set.end()) {
               continue; 
            }
            // 在原vector中存在当前元素加一的值
            int temp_val = nums[i];
            int counter = 1;
            while (my_set.find(temp_val + 1) != my_set.end()) {
                temp_val++;
                counter++;
            }
            res = max(res, counter);
        }
        return res;
    }
};




// // 排序之后一遍遍历
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int res = 1;
//         if (nums.size() == 0) {
//             return 0;
//         }
//         int counter = 1;
//         for (int i = 0; i < nums.size() - 1; i++) {
//             cout << counter << endl;
//             // 下一个元素就是当前元素加一
//             if (nums[i + 1] == nums[i] + 1) {
//                 counter++;
//                 res = max(res, counter);
//             }
//             // 下一个元素等于当前元素，跳过
//             else if (nums[i + 1] == nums[i]) {
//                 continue;
//             }
//             // 下一个元素不符合连续情况，重置counter
//             else {
//                 counter = 1;
//             }
//         }
//         return res;
//     }
// };
#include <iostream>
#include <vector>
using namespace std;

// leetcode 46
// leetcode LCR 083
// b站那个教程的swap写法
class Solution {
private: 
    void backtracking(vector<int>& nums, int startIndex, vector<vector<int>>& res) {
        if (startIndex == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        // i不能从startIndex + 1开始,这样会少了以nums[startIndex]为开头的情况
        // 虽然看上去i = startIndex时候swap(nums[startIndex], nums[i])这行没干事儿
        // 但是实际上保证了nums[startIndex]为开头的情况能被顺利计算
        for (int i = startIndex; i < nums.size(); i++) {
            swap(nums[startIndex], nums[i]);
            backtracking(nums, startIndex + 1, res);
            swap(nums[startIndex], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtracking(nums, 0, res);
        return res;
    }
};



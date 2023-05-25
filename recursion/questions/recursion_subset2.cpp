#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used) {
        // 第一次进入函数就push back一次，此时空集就已经被存入结果集了。
        result.push_back(path);
        if(startIndex >= nums.size()){
            return;
        }
        for(int i = startIndex ; i < nums.size() ; i++){
            // 和组合2那题一样的操作。
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            // 下面这种写法居然会报错...可能是第一次i为0的时候判断调用了nums[i-1]吧...所以要先判断i是不是大于0.
            // if(used[i-1] == false && nums[i] == nums[i-1] && i > 0){
            //     continue;
            // }  
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); // 去重需要排序
        backtracking(nums, 0, used);
        return result;
    }
};

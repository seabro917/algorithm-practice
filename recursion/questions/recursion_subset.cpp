#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        // 第一次进入函数就push back一次，此时空集就已经被存入结果集了。
        result.push_back(path);
        if(startIndex >= nums.size()){
            return;
        }
        for(int i = startIndex ; i < nums.size() ; i++){
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};
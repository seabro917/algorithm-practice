#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result; // 存放结果集
    vector<int> path; // 符合条件的结果
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum > target) { // 剪枝操作
            return; // 如果path.size() == k 但sum != targetSum 直接返回
        }
        if (sum == target){
            result.push_back(path);
            return;
        } 
        // 注意这里循环不包含i等于candidates的长度，因为考虑到数组的下标（和组合3的情况不一样，那个是可以一直取到值为n的数字。）
        for (int i = startIndex; i < candidates.size() ; i++) { 
            sum += candidates[i]; // 处理
            path.push_back(candidates[i]); // 处理
            backtracking(candidates, target, sum, i); 
            sum -= candidates[i]; // 回溯
            path.pop_back(); // 回溯
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        backtracking(candidates, target, 0, 0);
        return result;
    }
};



#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result; // 存放结果集
    vector<int> path; // 符合条件的结果
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum > target) { 
            return; 
        }
        if (sum == target){
            result.push_back(path);
            return;
        } 
        // 注意这里循环不包含i等于candidates的长度，因为考虑到数组的下标（和组合综合3的情况不一样，那个是可以一直取到值为n的数字。）
        for (int i = startIndex; i < candidates.size() ; i++) { 
            // 这里注意要加上i>0的判断条件，否则从数组第一个元素就开始判断的话会报错。
            // 具体为什么要这么判断见代码随想录...
            if(i>0 && candidates[i] == candidates[i-1] && used[i-1] == false){
                continue;
            }
            sum += candidates[i]; // 处理
            used[i] = true;
            path.push_back(candidates[i]); // 处理
            backtracking(candidates, target, sum, i+1, used); 
            sum -= candidates[i]; // 回溯
            used[i] = false;
            path.pop_back(); // 回溯
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};



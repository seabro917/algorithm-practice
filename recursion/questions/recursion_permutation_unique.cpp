// leetcode 46
// 全排列去重 逃课写法
class Solution {
  public:
    vector<vector<int> > permuteUnique(vector<int>& num) {
        vector<vector<int>> result;
        // 第一次是从初始位置开始。
        allpermute(num, 0, result);

        // 逃课写法，直接调用C++的sort和unique去重。
        // 相比无重复元素的全排列只多了这两行。
        // unique返回的是不重复元素的最后一个位置
        // erase(a, b)是删掉数组里面a到b位置的元素
        // 综上 这两行实现了去重
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        
        return result;
    }


    void allpermute(vector<int>& num, int position,
                    vector<vector<int>>& result) {
        // 从数组的position位置开始全排列。
        if (position == num.size() - 1) {
            result.push_back(num);
            return;
        }
        for (int i = position ; i < num.size() ; i++) {
            swap(num[position], num[i]);
            allpermute(num, position + 1, result);
            // 恢复初始状态 --> 还原现场。
            swap(num[position], num[i]);
        }
    }


    void swap(int& a, int& b) {
        int temp = 0;
        temp = b;
        b = a;
        a = temp;
    }
};







// leetcode 47
// 去重全排列
// 非逃课写法
class Solution {
private:
    void backtracking(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        // 和组合类型题目相比,不需要startIndex,因为每次都可以取前面的数字
        for (int i = 0; i < nums.size(); i++) {
            // 同层相同的数字不取
            if (i > 0 && used[i - 1] == false && nums[i] == nums[i - 1]) {
                continue;
            }
            if (!used[i]) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used, path, res);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<vector<int>> res;
        vector<int> path;
        // 去重问题要在回溯前排序,这样去重那一行逻辑才正确
        sort(nums.begin(), nums.end());
        backtracking(nums, used, path, res);
        return res;
        
    }
};






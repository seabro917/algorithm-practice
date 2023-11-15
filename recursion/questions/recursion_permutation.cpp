#include <iostream>
#include <vector>
using namespace std;

// leetcode 46
class Solution {
  public:
    vector<vector<int> > permute(vector<int>& num) {
        vector<vector<int>> result;
        // 第一次是从初始位置开始。
        allpermute(num, 0, result);
        return result;
    }


    void allpermute(vector<int>& num, int position, vector<vector<int>>& result) {
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




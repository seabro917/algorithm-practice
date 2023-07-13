#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    static bool comparator(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), comparator);
        if (intervals.size() == 1 || intervals.size() == 0){
            return intervals;
        }
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++){
            // 有重合，需要合并。
            if (intervals[i][0] <= right){
                right = max(right, intervals[i][1]);
            }
            // 没有重合，把之前合并好的结果存入res。
            else{
                vector<int> temp = {left, right};
                res.push_back(temp);
                left = intervals[i][0];
                right = intervals[i][1];
            }
            // 最后还要处理一次，无论有没有重合都可以直接push进去。
            if(i == intervals.size() - 1){
                vector<int> temp = {left, right};
                res.push_back(temp);
            }
        }
        return res;
    }
};
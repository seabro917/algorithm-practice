#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.cn/problems/insert-interval/solution/shou-hua-tu-jie-57-cha-ru-qu-jian-fen-cheng-3ge-ji/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        // 从前向后，遍历输入的intervals，会按照顺寻遇到三种情况：
        // 1.和新的区间没有重合，直接push就行，这里要根据端点情况判断。 
        // 2.开始有重合，要开始取重合的部分，这里也要根据端点情况判断。merge完毕后将merge的结果push进去。
        // 3.重合结束，剩下的原数组里的直接push即可。
        while (i < intervals.size() && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }

        // 注意这里要考虑到=0的极限情况。
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        while (i < intervals.size()){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
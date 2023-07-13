#include <iostream>
#include <vector>

using namespace std;


// https://leetcode.cn/problems/non-overlapping-intervals/solution/tan-xin-jie-fa-qi-shi-jiu-shi-yi-ceng-ch-i63h/

class Solution {
private: 
    static bool comparator(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        if (intervals.size() == 0){
            return 0;
        }
        int res = 1;
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] >= right){
                right = intervals[i][1];
                res++;
            }
        }
        return intervals.size() - res;
    }
};
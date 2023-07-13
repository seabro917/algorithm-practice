#include <iostream>
#include <vector>

using namespace std;

class Solution {
private: 
    static bool comparator(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comparator);
        if (points.size() == 1){
            return 1;
        }
        int res = 1;
        // int left = points[0][0];
        int right = points[0][1];
        for (int i = 1; i < points.size(); i++){
            if (points[i][0] <= right){
                right = min(right, points[i][1]);
                // left = max(left, points[i][0]);
            }
            else{
                right = points[i][1];
                res++;
            }
        }
        return res;
    }
};
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int result = 0;
        // map记录前两个数组每种和出现的次数。
        std::map<int, int> val_map;
        for(int a : nums1){
            for(int b : nums2){
                val_map[a+b]++;
            }
        }
        for(int c : nums3){
            for(int d : nums4){
                // 对于当前遍历到的nums3和nums4两个元素c和d，在nums1和nums2中存在符合条件的元素。
                if(val_map.find(0-(c+d)) != val_map.end()){
                    // val_map[a+b]代表前两个数组元素和为a+b出现的次数，有几次那么当前符合条件的可能性就有几种。
                    result += val_map[0-(c+d)];
                }
            }
        }
        return result;
    }
};
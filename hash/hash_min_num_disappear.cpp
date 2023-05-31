#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int minNumberDisappeared(vector<int>& nums) {
        std::set<int> val_set(nums.begin(), nums.end());
        int result;
        // set已排序，解end指针得到的即为最大值。
        int val_max = *val_set.end();
        for(int i = 1; i < val_max; i++){
            if(val_set.find(i) == val_set.end()){
                result = i;
                return result;
                break;
            }
        }
        // 例如[1,2,3,4,5]这样类似的情况，从1开始连续的正整数都存在于原输入vector中，则最后应该返回6（原vector中最大值+1）。
        return val_max+1;
    }
};
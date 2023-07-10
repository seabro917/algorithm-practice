#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int coverage = 0;
        if (nums.size() == 1){
            return true;
        }
        for (int i = 0; i <= coverage; i++){
            coverage = max(i + nums[i], coverage);
            if(coverage >= nums.size() - 1){
                return true;
            }
        }
        return false;
    }
};
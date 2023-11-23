#include <iostream>
#include <vector>

using namespace std;

// leetcode 55
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int coverage = 0;
        if (nums.size() == 1){
            return true;
        }
        for (int i = 0; i <= coverage; i++){
            // cout << coverage << endl;
            coverage = max(i + nums[i], coverage);
            if(coverage >= nums.size() - 1){
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
               cout << i << endl; 
               cout << k << endl; 
               return false;
            }
            // k记录的是到目前位置，最大的可能的能跳到的下标位置.
            k = max(k, i + nums[i]);
        }
        return true;
    }
};


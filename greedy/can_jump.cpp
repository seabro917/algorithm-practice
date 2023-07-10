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
            k = max(k, i + nums[i]);
        }
        return true;
    }
};


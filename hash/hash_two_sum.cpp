#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> val_map;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            // 如果（target-当前遍历到的数组元素）不存在于map中，则存入。
            if(val_map.find(target - nums[i]) == val_map.end()){
                // 数值作为key，下标作为value。
                val_map.insert(pair <int, int> (nums[i], i));
            }
            // 在map中找到符合条件的数值，则返回结果。
            else{
                result.push_back(val_map.find(target - nums[i])->second);
                result.push_back(i);
            }
        }        
        return result;
    }
};
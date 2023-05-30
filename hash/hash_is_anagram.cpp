#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

// 同样思路，直接将每个vector的数字存入map，之后遍历其中一个map，如果当前遍历到的key也存在于第二个map中，则说明该元素应该被放入交集内。
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result; 
        std::map<int, int> map_1;
        std::map<int, int> map_2;

        // 将第一个vector的数字压入map.
        for(int i = 0 ; i < nums1.size(); i++){
            if (map_1.count(nums1[i]) == 0){
                map_1.insert(pair <int, int> (nums1[i], 1));
            }
            else{
                std::map<int, int>::iterator itr_find = map_1.find(nums1[i]);
                // second代表的就是value值，first代表的是key的值。(注意要用迭代器)
                itr_find->second = itr_find->second + 1;
            }
        }   
        // 将第二个vector的数字压入map.
        for(int i = 0 ; i < nums2.size(); i++){
            if (map_2.count(nums2[i]) == 0){
                map_2.insert(pair <int, int> (nums2[i], 1));
            }
            else{
                std::map<int, int>::iterator itr_find = map_2.find(nums2[i]);
                // second代表的就是value值，first代表的是key的值。(注意要用迭代器)
                itr_find->second = itr_find->second + 1;
            }
        }  
        for(std::map<int, int>::iterator it = map_1.begin(); it != map_1.end(); it++){
            if(map_2.count(it->first) != 0){
                result.push_back(it->first);
            }
        }
        return result;
    }   
};


// 直接从两个输入的vector构造set
class Solution_ {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &num) {
        vector<vector<int>> result;
        // 要先对原输入数组进行排序。
        sort(num.begin(), num.end());
        // 原输入数组不足3个元素的情况，直接返回空集。
        if(num.size() < 3){
            return result;
        }
        for(int i = 0; i < num.size(); i++){
            int cur_value = num[i];
            int left_ptr = i + 1;
            int right_ptr = num.size() - 1;
            // 去重(原输入数组已经排序，所以可以这样去重)。
            // 这里的第一个判断条件是为了考虑到原输入数组所有元素值都相等的情况。
            if(i != 0 && num[i] == num[i-1]){
                continue;
            }
            while(left_ptr < right_ptr){         
                if(num[left_ptr] + num[right_ptr] == 0 - cur_value && left_ptr < num.size()-1){
                    // cout << num[left_ptr] << endl;
                    result.push_back({num[i], num[left_ptr], num[right_ptr]});
                    // 左右指针对应的数值的去重。
                    // 第一个判断条件是为了考虑到原输入数组所有元素值都相等的情况。
                    while(left_ptr + 1 < right_ptr && num[left_ptr] == num[left_ptr+1]){
                        left_ptr++;
                    }
                    while(left_ptr < right_ptr -1 && num[right_ptr] == num[right_ptr-1]){
                        right_ptr--;
                    }
                    left_ptr++;
                    right_ptr--;
                    continue;
                }
                // 当前两个指针对应的和大于目标值。
                if(num[left_ptr] + num[right_ptr] > 0 - cur_value){
                    right_ptr--;
                    continue;
                }
                // 当前两个指针对应的和小于目标值。
                if(num[left_ptr] + num[right_ptr] < 0 - cur_value){
                    left_ptr++;
                    continue;
                }
            }
        }
        return result;
    }
};
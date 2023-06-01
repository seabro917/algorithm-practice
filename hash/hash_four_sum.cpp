#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &num, int target)
    {
        vector<vector<int>> result;
        // 要先对原输入数组进行排序。
        sort(num.begin(), num.end());
        // 原输入数组不足4个元素的情况，直接返回空集。
        if (num.size() < 4)
        {
            return result;
        }
        for (int i = 0; i < num.size(); i++)
        {
            // 去重(原输入数组已经排序，所以可以这样去重)。
            // 这里的第一个判断条件是为了考虑到原输入数组所有元素值都相等的情况。
            if (i != 0 && num[i] == num[i - 1])
            {
                continue;
            }
            // 剪枝
            // if(num[i] > target && num[i] > 0){
            //     break;
            // }
            for (int j = i + 1; j < num.size(); j++)
            {
                int left_ptr = j + 1;
                int right_ptr = num.size() - 1;
                if (j != i + 1 && num[j] == num[j - 1])
                {
                    continue;
                }
                // 剪枝
                // if(num[i] + num[j] > target && num[i] + num[j] > 0){
                //     break;
                // }
                while (left_ptr < right_ptr)
                {
                    // 这里注意一定是判断完当前组合符合条件后,再去重, 不然会漏掉四个连续值的情况.
                    // 强转成long类型-->只是为了过leetcode纯恶心人的测试用例。
                    if ((long)num[left_ptr] + (long)num[right_ptr] == (long)target - (long)num[i] - (long)num[j] && left_ptr < num.size() - 1)
                    {
                        // cout << num[left_ptr] << endl;
                        result.push_back({num[i], num[j], num[left_ptr], num[right_ptr]});
                        // 左右指针对应的数值的去重。
                        // 第一个判断条件是为了考虑到原输入数组所有元素值都相等的情况。
                        while (left_ptr + 1 < right_ptr && num[left_ptr] == num[left_ptr + 1])
                        {
                            left_ptr++;
                        }
                        while (left_ptr < right_ptr - 1 && num[right_ptr] == num[right_ptr - 1])
                        {
                            right_ptr--;
                        }
                        left_ptr++;
                        right_ptr--;
                        // continue;
                    }
                    // 当前两个指针对应的和大于目标值。
                    if ((long)num[left_ptr] + (long)num[right_ptr] > (long)target - (long)num[i] - (long)num[j])
                    {
                        right_ptr--;
                        // continue;
                    }
                    // 当前两个指针对应的和小于目标值。
                    if ((long)num[left_ptr] + (long)num[right_ptr] < (long)target - (long)num[i] - (long)num[j])
                    {
                        left_ptr++;
                        // continue;
                    }
                }
            }
        }
        return result;
    }
};
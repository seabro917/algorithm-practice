// leetcode 75
// 双指针
// https://leetcode.cn/problems/sort-colors/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int idx = 0;
        while (idx <= right) {
            if (nums[idx] == 0) {
                swap(nums[left], nums[idx]);
                left++;
                idx++;
            }
            else if (nums[idx] == 1) {
                idx++;
            }
            // 这里idx不可以++,例如如下情况:
            // ... 2 ...... 2 2 2 2
            //    idx     right
            // 即:right本身对应的数字就是2了,那么由于idx对应的是2,交换二者数字,交换完之后idx位置还是2
            // 如果这时候idx++的话那么这个2就会还被保留在未处理区
            // 对于上面nums[idx] == 0的情况可以可以idx++是因为遍历是正向遍历的,当前idx位置以前肯定没有任何一个位置的值为0
            // 所以类似的,如果考虑反向遍历,那么就是nums[idx] == 0的情况不可以idx--,而nums[idx] == 2的情况可以idx--
            else {
                swap(nums[right], nums[idx]);
                right--;
            }
        }
    }
};


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int left = 0;
//         int right = nums.size() - 1;
//         int idx = right;
//         while (left <= idx) {
//             if (nums[idx] == 0) {
//                 swap(nums[left], nums[idx]);
//                 left++;
//                 // idx++;
//             }
//             else if (nums[idx] == 1) {
//                 idx--;
//             }
//             else {
//                 swap(nums[right], nums[idx]);
//                 right--;
//                 idx--;
//             }
//         }
//     }
// };
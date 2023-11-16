// leetcode 2779
// 先排序之后的滑动窗口
// https://leetcode.cn/problems/maximum-beauty-of-an-array-after-applying-operation/solutions/2345805/pai-xu-shuang-zhi-zhen-by-endlesscheng-hbqx/
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int res = 0;
        sort(nums.begin(), nums.end());
        // 这里要把两个指针放在循环外面不然会超时
        // 因为如果放在循环里面每次遍历一个左端点的时候右端点都要重新开始跑，就没有利用到之前的结果
        // 而实际上是对于一个left，当right不符合之后，我们按照外层for循环移动left，这时候之前的right不需要重新开始从left下一个位置开始跑
        // 而是可以继续之前的跑，因为反正要求的是最长的序列，就算出现
        
        // 1) 一个left
        // x     x     x     x     x     x     x     x
        // left                          right right*      --> right是符合的right*是不符合的,于是left根据外循环移动
        
        // 2) 下一个遍历到的left,right依旧保持遍历上一个left时候的值,即不是从头left+1开始重新跑
         // x     x     x     x     x     x     x     x
        //        left                          right*     --> 假设此时right*依旧不满足nums[right] - nums[left] <= 2k的条件
        // 那么其实也无所谓，根据while会直接接着往后面遍历下一个left，而且因为要求的是最长子序列，所以记录的结果也没问题，因为left往后移了一个位置，得到的长度肯定比之前短。 
        int left = 0; 
        int right = 0;
        for (; left < nums.size(); left++) {
            // int right = left + 1;
            while (right < nums.size() && nums[right] - nums[left] <= 2 * k) {
                right++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};
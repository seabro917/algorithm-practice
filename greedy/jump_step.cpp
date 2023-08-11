#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int maxPos = 0;
        int end = 0;
        for (int i = 0; i < nums.size() - 1; i++){
            maxPos = max(maxPos, nums[i] + i);
            // 这个if代表当前跳跃结束（因为到达了你当前这一跳最远可以到达的距离），同时要赋值你下一跳最远能跳到的距离。
            // 其实可以看出来，在第（n-1）跳的过程中，就已经在更新第n跳（也就是下一跳）的最远可以跳到的距离。
            // i遍历到end的时候，其实不代表end就一定是我要选取的跳点，而是因为end代表的是你当前这一跳最远可能跳到的距离 
            //      --> 即：当到达end这个边界的时候，我们必须做出一次跳跃“选择”！！但是具体选择哪一个位置作为跳点，我们不知道，但是我们至少知道我们到尽头了到end了。
            // 因为事实上不管你在这个范围内选取哪个点作为跳点，一旦i到end了，肯定就代表了这一跳结束，因为end是你可能跳到的最远的距离啊，不能再远了，再远就是下一跳了。
            if (i == end){
                end = maxPos;
                step++;
            }
        }
        return step;
    }
};
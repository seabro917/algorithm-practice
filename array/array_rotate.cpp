// leetcode 189
// 额外内存做法
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            res[(i + k) % nums.size()] = nums[i];
        }
        nums.assign(res.begin(), res.end());
    }
};

// 还有一种解法是通过三次反转完成的
// 评论区：

// nums = "----->-->"; k =3
// result = "-->----->";

// procedures:
// 1. reverse "----->-->" we can get "<--<-----"
// 2. reverse "<--" we can get "--><-----"
// 3. reverse "<-----" we can get "-->----->"
// this visualization help me figure it out :)
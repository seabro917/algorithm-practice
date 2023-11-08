// leetcode 238
// https://leetcode.cn/problems/product-of-array-except-self/solutions/11472/product-of-array-except-self-shang-san-jiao-xia-sa/?envType=study-plan-v2&envId=top-100-liked
// 这题解太nb了...讲要求的数组拆分成两个部分，找到之间的关系！然后两遍遍历根据这个关系来迭代更新。
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 这里要初始化为1，因为考虑到遍历中不会初始化第一个位置的右边乘积，而且之后要做乘积，所以要设为1
        vector<int> res(nums.size(), 1);
        // 两个三角的中间值，要初始化为1是因为主对角线是1，每次更新一行的时候都是和上一行有关系.
        int temp_left = 1;
        int temp_right = 1;
        // 更新i左边的乘积，即图中的左下角三角
        // 下标从1开始，因为对于res[0]而言，nums中没有左边的值，直接就是1
        for (int i = 1; i < nums.size(); i++) {
            temp_left = temp_left * nums[i - 1];
            res[i] = temp_left;
            // cout << temp_left << endl;
        }
        // 更新i右边的值，即图中的右上三角形
        // 下标从后往前
        for (int i = nums.size() - 2; i >= 0; i--) {
            temp_right = temp_right * nums[i + 1];
            res[i] = res[i] * temp_right;
            cout << temp_right << endl;
        }
        return res;
    }
};
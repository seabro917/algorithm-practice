// leetcode 2735
// 枚举操作次数,找到最小值
// 官方自己说自己题目描述错了...
// https://leetcode.cn/problems/collecting-chocolates/solutions/2580148/shou-ji-qiao-ke-li-by-leetcode-solution-bjyp/
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        // 最多只会操作n-1次,循环数组,操作n次和操作0次效果一样
        // 其实应该是min_val[i][k]代表第i种类型的巧克力在进行了k次操作之后最小可能成本
        // 但是考虑到min_val[i][k]仅和min_val[i][k]与nums[(i + k) % n]有关,可以在每次外循环遍历操作次数k的时候更新最小总成本,所以只用了一维数组
        // 这个数组每个元素代表的是对应下标的类型巧克力在进行了k次操作之后可能的最小成本
        // 不需要关心这个最小成本实际上是在第几次操作的时候得到的,因为反正可以随时购买,无所谓
        // 一次不操作的时候成本就是原先的成本
        vector<int> min_val(nums);
        // 初始化答案为一次不操作的情况
        long long res = accumulate(nums.begin(), nums.end(), 0LL);
        // 枚举操作次数
        for (int k = 1; k < n; k++) {
            // 计算每一个类型的巧克力在操作k次的情况下最小成本是多少
            for (int i = 0; i < n; i++) {
                min_val[i] = min(min_val[i], nums[(i + k) % n]);
            }
            // 更新最小总成本
            res = min(res, (long long)(k) * (long long)x + accumulate(min_val.begin(), min_val.end(), 0LL));
        }
        return res;
    }
};
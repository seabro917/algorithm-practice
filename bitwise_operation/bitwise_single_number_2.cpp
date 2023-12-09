// leetcode 137
// https://leetcode.cn/problems/single-number-ii/solutions/2482832/dai-ni-yi-bu-bu-tui-dao-chu-wei-yun-suan-wnwy/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        // int是32比特,统计每一个位置1的个数
        for (int i = 0; i < 32; i++) {
            // 当前位置原nums中所有数字一共有多少个1
            int cur_count = 0;
            for (int j = 0; j < nums.size(); j++) {
                cur_count +=  (nums[j] >> i) & 1;
            }
            res |= (cur_count % 3) << i;
        }
        return res;
    }
};
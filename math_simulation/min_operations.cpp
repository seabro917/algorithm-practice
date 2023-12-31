// leetcode 1599
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int res = -1;
        // 当前得到的利润
        int cur_profit = 0;
        int max_profit = 0;
        // 旋转的次数
        int operations = 0;
        // 上一轮因为座位满了还在等待的游客数
        int previous_wait = 0;
        for (int i = 0; i < customers.size() || previous_wait > 0; i++) {
            operations++;
            int cur_customers;
            // 还是在遍历数组内的数据
            if (i < customers.size()) {
                cur_customers = customers[i] + previous_wait;   
            }
            // customers数组已经遍历结束,现在处理的是剩下的游客.
            else {
                cur_customers = previous_wait;
            }
            // 本轮想登船的游客数小于等于4,那么就没有剩下的了,全部登船并且计算得到的利润
            // 注意这里就算人数不满4个也要进行旋转
            if (cur_customers <= 4) {
                previous_wait = 0;
                cur_profit += cur_customers * boardingCost - runningCost;
            } 
            // 本轮想登船的游客数大于4,那么只能搭乘4,且计算剩下来的游客数
            else {
                previous_wait = cur_customers - 4;
                cur_profit += 4 * boardingCost - runningCost;
            }
            // 更新维护的最大利润
            if (cur_profit > max_profit) {
                res = operations;
                max_profit = cur_profit;
            }
        }
        return res;
    }
};


// 下面这个写法直接考虑了所有游客总数,错了...
// class Solution {
// public:
//     int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
//         // 四个游客满一组得到的利润都不足以支付一次旋转的成本,那么肯定就是没有正利润
//         if (4 * boardingCost <= runningCost) {
//             return -1;
//         }
//         else {
//             // 四个游客满一组得到的利润大于一次旋转的成本,那么只用看所有游客取模之后最后一组的人登船得到的收入与一次旋转成本的大小关系
//             int total_count = accumulate(customers.begin(), customers.end(), 0);
//             int num_group = total_count / 4;
//             int remaining = total_count % 4;
//             cout << num_group << endl;
//             cout << remaining << endl;
//             // 最后一组可以得到的利润仍然大于一次旋转成本,那么就是所有游客都被搭乘了一次
//             if (remaining * boardingCost > runningCost) {
//                 // 一开始看错题目了,输出成可以得到的利润了orz
//                 // return remaining == 0 ? total_count * boardingCost - num_group * runningCost : total_count * boardingCost - (num_group + 1) * runningCost;
//                 return remaining == 0 ? num_group: num_group + 1;
//             } 
//             // 搭乘最后一组得到的利润不足以支付一次旋转成本,最后一组不搭乘
//             else {
//                 // return remaining == 0 ? total_count * boardingCost - num_group * runningCost : (total_count - remaining) * boardingCost - num_group * runningCost;
//                 return num_group == 0 ? -1 : num_group;
//             } 
//         }
//         return -1;
//     }
// };




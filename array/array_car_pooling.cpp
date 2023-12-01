// leetcode 1094
// https://labuladong.github.io/algo/di-yi-zhan-da78c/shou-ba-sh-48c1d/xiao-er-me-c304e/
// 差分数组 上面那个题解写的太好了
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 记录当前位置(公里数处)有多少个人在车上
        vector<int> kilos(1001, 0);
        // 构建差分数组
        vector<int> diff(1001, 0);
        // 对差分数组进行加减操作,这对应在里程范围内车上的人会变多或者变少
        for (int i = 0; i < trips.size(); i++) {
            diff[trips[i][1]] += trips[i][0];
            diff[trips[i][2]] -= trips[i][0];
        }
        for (auto i : diff) {
            cout << i << endl; 
        }
        // 从差分数组恢复原始数组kilos
        // diff[i] = kilos[i] - kilos[i - 1];
        // 注意差分数组和原始数组的第一个位置都是相等的
        kilos[0] = diff[0];
        for (int i = 1; i < kilos.size(); i++) {
            kilos[i] = diff[i] + kilos[i - 1];
        }
        for (auto i : kilos) {
            cout << i << endl; 
        }
        // 此时kilos数组里面记录了所有公里数处车上的人数,遍历kilos数组,如果有任意一个位置大于了capacity,那么说明超载了
        for (int i = 0; i < kilos.size(); i++) {
            if (capacity < kilos[i]) {
                return false;
            }
        }
        return true;
    }
};
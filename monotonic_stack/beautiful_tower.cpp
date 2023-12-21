// leetcode 2866
// 单调栈,前后缀
// https://leetcode.cn/problems/beautiful-towers-ii/solutions/2456562/qian-hou-zhui-fen-jie-dan-diao-zhan-pyth-1exe/
// https://www.bilibili.com/video/BV1yu4y1z7sE/?vd_source=dabcffd1cd0c95a73e0d13f61da7ae44
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long res = 0;
        int n = maxHeights.size();
        // 记录前后缀和的数组
        vector<long long> suf(n + 1, 0);
        vector<long long> pre(n + 1, 0);

        // 单调栈中存放下标,不直接存放数值,这一点和之前几个单调栈的题目一致
        stack<int> stk_suf;
        // 计算后缀和
        stk_suf.push(n); // 哨兵,以便第一次的时候就能记录相同的数字出现了几次
        long long suf_sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            // 这里因为加入了dummy哨兵,所以不是判断栈为不为空
            while (stk_suf.size() > 1 && maxHeights[i] <= maxHeights[stk_suf.top()]) {
                int num_to_be_removed_idx = stk_suf.top();
                stk_suf.pop();
                // 删掉这一段下标的元素,之后在while结束之后再加入更新的元素
                // 这里就体现了提前加入哨兵的作用
                // 假设要找 ..., 2, 7, 7, 7 这样的,一开始栈内先加入n,遍历到2的时候(下标为n-3),栈顶是n-3,然后pop,pop之后的栈顶变成了n,这样n-(n-3)就是3,将三个7全都更新为2
                suf_sum -= (long long) maxHeights[num_to_be_removed_idx] * (stk_suf.top() - num_to_be_removed_idx);
            }
            suf_sum += (long long) maxHeights[i] * (stk_suf.top() - i);
            suf[i] = suf_sum;
            stk_suf.push(i);
        }

        // for (auto x : suf) {
        //     cout << x << endl;
        // }

        // 计算前缀和,和计算后缀和的单调栈逻辑一样,除了遍历顺序改变
        stack<int> stk_pre;
        stk_pre.push(-1); // 哨兵,以便第一次的时候就能记录相同的数字出现了几次
        long long pre_sum = 0;
        for (int i = 0; i < n; i++) {
            while (stk_pre.size() > 1 && maxHeights[i] <= maxHeights[stk_pre.top()]) {
                int num_to_be_removed_idx = stk_pre.top();
                stk_pre.pop();
                pre_sum -= (long long) maxHeights[num_to_be_removed_idx] * (num_to_be_removed_idx - stk_pre.top());
            }
            pre_sum += (long long) maxHeights[i] * (i - stk_pre.top());
            pre[i] = pre_sum;
            stk_pre.push(i);
        }

        // for (auto x : pre) {
        //     cout << x << endl;
        // }

        for (int i = 0; i < n; i++) {
            // 注意对于前缀和与后缀和,计算的时候都是把当前下标算进去了,不要算重复了
            res = max(res, pre[i] + suf[i + 1]);
        }

        return res;
    }
};
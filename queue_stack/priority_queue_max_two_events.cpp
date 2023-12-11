// leetcode 2054
// https://leetcode.cn/problems/two-best-non-overlapping-events/solutions/1075386/yong-you-xian-dui-lie-wei-hu-ling-yi-ge-8ld3x/
// 排序+优先队列
class Solution {
public:
    typedef pair<int, int> PAIR;
    int maxTwoEvents(vector<vector<int>>& events) {
        int pre_max = INT32_MIN, res = INT32_MIN;
        // 小顶堆,按照pair的第一个int(事件结束时间)升序排序
        priority_queue<PAIR, vector<PAIR>, greater<PAIR>> que;
        // 按照事件的开始时间升序排序event数组
        sort(events.begin(), events.end());
        // 将每个活动的push进队列,队列中按照每个活动的结束时间升序排列.
        for (int i = 0; i < events.size(); i++) {
            que.push({events[i][1], events[i][2]});
        }
        // 开始遍历事件i,如果当前遍历到的活动的开始时间大于小顶堆顶部的活动的结束时间,那么这一对就符合条件
        // 符合就弹出,pre_max记录的是当前遍历到的事件之前符合条件的事件中的最大价值
        // 等到小顶堆堆顶的不符合了,就更新能得到得可能的最大价值是多少
        //     ----> 可能是两个事件得到最大价值(当前遍历到的事件i本身的价值(cur_val)+事件i之前符合条件的另一个事件价值(pre_max)),也有可能是当前事件i自己一个得到最大价值(cur_val)
        // 继续遍历下一个事件i + 1,值得注意的是对于事件i,小顶堆while判断结束后得到的pre_max对应的那个事件,是一定符合与事件i + 1 '配对' 的条件的.
        // 这是因为事先对events进行了按照事件开始时间的升序排序.所以在查看小顶堆堆顶的while循环中,我们才能每次只要找到堆顶符合条件的,直接就可以pop掉,而不用担心情况被漏算.
        //     ----> (pre_max对应的事件的结束时间都在事件i的开始时间之前了,那么肯定也在事件i + 1的开始时间之前)
        for (int i = 0; i < events.size(); i++) {
            int cur_start = events[i][0], cur_val = events[i][2];
            // 查找对于当前这个事件i,符合条件的活动(结束时间在它开始时间之前的活动)之中,最大的价值是多少
            while (!que.empty() && que.top().first < cur_start) {
                // 当前事件i得到的pre_max对应的那个事件的结束时间一定也在下一个要遍历的事件i + 1的开始时间之前
                pre_max = max(pre_max, que.top().second);
                que.pop();
            }
            res = max({res, pre_max + cur_val, cur_val});
        }
        return res;
    }
};
// leetcode 1962
// 优先队列,找数目最大的移就完事了
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // 大顶堆
        // priority_queue<int, vetor<int>, less<int>> que;
        priority_queue<int> que(piles.begin(), piles.end());
        int sum = 0;
        for (int i = 0; i < k; i++) {
            int temp = que.top();
            que.pop();
            que.push(temp - temp / 2);
        }
        while (!que.empty()) {
            sum += que.top();
            que.pop();
        }
        return sum;
    }
};
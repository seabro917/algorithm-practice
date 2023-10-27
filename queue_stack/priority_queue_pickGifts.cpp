// leetcode 2558
// priority queue
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> que(gifts.begin(), gifts.end());
        for (int i =0; i < k; i++) {
            long long temp_max = que.top();
            que.pop();
            que.push(sqrt(temp_max));
        }
        long long sum = 0;
        while (!que.empty()) {
            sum += que.top();
            que.pop();
        }
        return sum;
    }
};

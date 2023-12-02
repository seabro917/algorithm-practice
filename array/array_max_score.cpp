// leetcode 1423
// 滑动窗口,用窗口包住要被删除掉的子数列
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum_total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int n = cardPoints.size();
        int res = 0;
        int sum_in_window_min = accumulate(cardPoints.begin(), cardPoints.begin() + n - k, 0);
        int sum_in_window_temp = sum_in_window_min;
        // 维护一个长度为n-k的窗口
        for (int i = (n - k); i < cardPoints.size(); i++) {
            // 加入新元素,移除旧元素.
            sum_in_window_temp += cardPoints[i];
            sum_in_window_temp -= cardPoints[i - (n - k)];
            sum_in_window_min = min(sum_in_window_min, sum_in_window_temp);
        }
        return sum_total - sum_in_window_min;
    }
};
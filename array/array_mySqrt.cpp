// leetcode 69
// 暴力二分
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int res = 0;
        while (left <= right) {
            // 防止left + right的int过大溢出
            int mid = left + (right - left) / 2;
            // 同样防止平方结果溢出
            if ((long long)mid * mid <= x) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};
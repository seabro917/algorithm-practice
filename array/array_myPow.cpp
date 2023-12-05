// leetcode 50
// 直接奇偶分类讨论吧...
class Solution {
private:
    // 输入n一定是自然数
    double halfPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double half = halfPow(x, n / 2);
        return n % 2 == 0 ? half * half : half * half * x; 
        
        // 下面这样写直接超时了...上面是记忆化递归?
        // if (n % 2 == 0) {
        //     return halfPow(x, n / 2) * halfPow(x, n / 2);
        // }
        // else {
        //     return halfPow(x, n / 2) * halfPow(x, n / 2) * x;
        // }
    }
public:
    double myPow(double x, int n) {
        // 测试用例真恶心啊...
        long long N = n;
        return N >= 0 ? halfPow(x, N) : 1 / halfPow(x, -N); 
    }
};
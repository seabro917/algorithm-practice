// leetcode 59
class Solution {
public:
    // 循环不变量，拐点统一算在下一条边内。
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        // 一共要循环的次数，n为奇数的话要最后把矩阵中间的值给补上。
        int loop = n / 2;
        // 起始位置，每个loop结束之后x和y的起始位置各加一。
        int start_x = 0;
        int start_y = 0;
        int num = 1;
        while (loop--) {
            int i = start_y;
            int j = start_x;
            for (j; j < n - (start_x + 1); j++) {
                res[i][j] = num;
                num++;
            }
            for (i; i < n - (start_y + 1); i++) {
                res[i][j] = num;
                num++;
            }
            for (j; j > start_x; j--) {
                res[i][j] = num;
                num++;
            }
            for (i; i > start_y; i--) {
                res[i][j] = num;
                num++;
            }
            start_x++;
            start_y++;

        }
        if (n%2 == 1) {
            res[n/2][n/2] = num;
        }
        return res;
    }
};
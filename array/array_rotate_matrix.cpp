// leetcode 48
// 先对角线反转，再vertical反转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 沿副对角线翻转(其实沿主对角线写起来更简单)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
        // for (auto nums:matrix) {
        //     for (auto num:nums) {
        //         cout << num << endl;
        //     }
        // }

        // 沿vertical方向翻转
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }

    }
};
// leetcode 74
// 先定位在哪一行，再在该行进行搜索，该行内没有找到的话则原matrix内找不到.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int target_row = INT32_MAX;
        // 用行内最后一个元素和target比较
        for (int i = 0; i < m; i++) {
            if (matrix[i][n - 1] >= target) {
                target_row = i;
                break;
            }
        }
        if (target_row == INT32_MAX) {
            return false;
        }
        // 遍历定位到的行
        for (int i = 0; i < n; i++) {
            if (matrix[target_row][i] == target) {
                return true;
            }
        }
        return false;
    }
};
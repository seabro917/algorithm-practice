// leetcode 73
class Solution {
private:
    void setZero(vector<vector<int>>& matrix, pair<int, int> position) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 列置零
        for (int i = 0; i < m; i++) {
            matrix[i][position.second] = 0;
        }
        // 行置零
        for (int i = 0; i < n; i++) {
            matrix[position.first][i] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> positions;
        int m = matrix.size();
        int n = matrix[0].size();
        // 记录原矩阵中元素值为0的坐标
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    positions.push_back({i, j});
                }
            }
        }
        // 坐标位置行列元素置零
        for (int i = 0; i < positions.size(); i++) {
            setZero(matrix, positions[i]);
        }
    }
};
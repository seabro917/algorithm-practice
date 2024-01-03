// leetcode 2397
// 回溯+位运算
// matrix的行和列大小不超过12,每一行用一个int记录1出现的位置,计算每一个组合能覆盖的行数
class Solution {
private:
    int res = INT32_MIN;
    vector<vector<int>> combinations;
    vector<int> combination;
    // 回溯寻找组合,计算每个组合能覆盖的行数,维护最大能覆盖的行数
    void backtracking(int n, int k, int startIndex, vector<int>& combination, vector<vector<int>>& matrix, vector<int> row_masks) {
        if (combination.size() == k) {
            // cout << "one combination" << endl;
            // for (auto c : combination) {
            //     cout << c << ' ';
            // }
            // cout << endl;
            // 一个组合寻找完毕,计算当前这个column的组合覆盖了几行
            check_row_overwrite(matrix, combination, row_masks);
            return;
        }
        else {
            for (int i = startIndex; i < n; i++) {
                combination.push_back(i);
                backtracking(n, k, i + 1, combination, matrix, row_masks);
                combination.pop_back();
            }
        }
    }
    void check_row_overwrite(vector<vector<int>>& matrix, vector<int> combination, vector<int> row_masks) {
        int count = 0;
        int cur_mask = 0;
        for (int i = 0; i < combination.size(); i++) {
            cur_mask |= 1 << combination[i];
        }
        for (int i = 0; i < matrix.size(); i++) {
            if ((row_masks[i] & cur_mask) == row_masks[i]) {
                count++;
            }
        }
        res = max(res, count);
    }
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        combination.clear();
        vector<int> row_masks;
        // 记录输入矩阵每一行的1的位置
        for (int i = 0; i < matrix.size(); i++) {
            int cur_row = 0;
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 1) {
                    cur_row |= 1 << j; 
                }
            }
            row_masks.push_back(cur_row);
        }
        // for (auto c : row_masks) {
        //     cout << c << endl;
        // }
        backtracking(matrix[0].size(), numSelect, 0, combination, matrix, row_masks);
        return res;
    }
};
// leetcode 2661
// 哈希
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // 记录每一行和每一列是否被填满
        vector<int> row_filled_count(mat.size());
        vector<int> col_filled_count(mat[0].size());
        // 用map记录每个元素在矩阵里面的坐标
        unordered_map<int, pair<int, int>> my_map;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                my_map[mat[i][j]] = {i, j};
            }
        }
        // 遍历数组 
        for (int i = 0; i < arr.size(); i++) {
            row_filled_count[my_map[arr[i]].first]++;
            col_filled_count[my_map[arr[i]].second]++;
            // 当前这个元素所在的行或者列被塞满了
            if (row_filled_count[my_map[arr[i]].first] == mat[0].size() || col_filled_count[my_map[arr[i]].second] == mat.size()) {
                return i;
            }
        }
        return 520;
    }
};
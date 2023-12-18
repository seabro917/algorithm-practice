// leetcode 1901
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row_size = mat.size(), col_size = mat[0].size();
        
        auto getItem = [&](int i, int j) -> pair<int, int> {
            if (i == -1 || i == row_size || j == -1 || j == col_size) {
                return {0, 0};
            }
            return {1, mat[i][j]};
        };

        int low = 0, high = row_size - 1;
        // vertical方向的二分,找到每行的最大值
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int max_idx = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            if (getItem(mid, max_idx) > getItem(mid - 1, max_idx) && getItem(mid, max_idx) > getItem(mid + 1, max_idx)) {
                return {mid, max_idx};
            }
            else if (getItem(mid, max_idx) < getItem(mid + 1, max_idx)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return {};
    }
};
// leetcode 54
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l = 0;
        int r = matrix[0].size() - 1;
        int t = 0;
        int b = matrix.size() - 1;
        vector<int> res;
        while (true) {
            // 注意这种写法是把拐点放在当前边处理，而不是下一条边。
            for (int i = l; i <= r; i++) {
                res.push_back(matrix[t][i]);
            }
            if (++t > b) {
                break;
            }
            for (int i = t; i <= b; i++) {
                res.push_back(matrix[i][r]);
            }
            if (l > --r) {
                break;
            }
            for (int i = r; i >= l; i--) {
                res.push_back(matrix[b][i]);
            }
            if (t > --b) {
                break;
            }
            for (int i = b; i >= t; i--) {
                res.push_back(matrix[i][l]);
            }
            if (++l > r) {
                break;
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int y_size = matrix.size();
        int x_size = matrix[0].size(); 
        int loop = min(x_size, y_size) / 2;
        int start_x = 0;
        int start_y = 0;
        while (loop--) {
            int i = start_y;
            int j = start_x;
            for (j; j < x_size - (start_x + 1); j++) {
                res.push_back(matrix[i][j]);
            }
            for (i; i < y_size - (start_y + 1); i++) {
                res.push_back(matrix[i][j]);
            }
            // cout << i << endl;
            // cout << j << endl;
            for (j; j > start_x; j--) {
                res.push_back(matrix[i][j]);
            }
            for (i; i > start_y; i--) {
                res.push_back(matrix[i][j]);
            }
            start_x++;
            start_y++;
        }
        loop = min(x_size, y_size) / 2;
        // 如果沿x和y方向的原矩阵大小的短板为奇数，那么分类考虑到底x是短板还是y是短板。
        // 如果x方向的大小是短板，那么还要将最后中间的一列从上往下放入结果集。
        // 如果y方向的大小是短板，那么还要将最后中间的一行从左往右放入结果集。
        if (min(x_size, y_size) % 2 == 1) {
            if (x_size <= y_size) {
                for (int i = loop; i < y_size - loop; i++) {
                    res.push_back(matrix[i][x_size / 2]);
                }
            }
            else if (x_size > y_size) {
                for (int j = loop; j < x_size - loop; j++) {
                    res.push_back(matrix[y_size / 2][j]);
                }
            }
        }
        return res;
    }
};
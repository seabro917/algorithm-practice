// // leetcode 36
// // 哈希
// // https://leetcode.cn/problems/valid-sudoku/solutions/1002073/gong-shui-san-xie-yi-ti-san-jie-ha-xi-bi-ssxp/?envType=study-plan-v2&envId=top-interview-150
// // 因为只是根据borad中已经填好的数字要判断是否为有效合法的数独,直接对三个条件(每个行,列,区域内每个数字只出现依次)进行判断即可
// // 用到了之前赎罪信的哈希数组思想

// // 数位哈希详细注释题解
// // https://leetcode.cn/problems/valid-sudoku/solutions/1270130/jie-zhu-wei-yun-suan-rang-su-du-fei-qi-l-8p60/?envType=study-plan-v2&envId=top-interview-150
// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         vector<vector<int>> col_check(9, vector<int>(9, 0));
//         vector<vector<int>> row_check(9, vector<int>(9, 0));
//         vector<vector<int>> area_check(9, vector<int>(9, 0));
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 char cur = board[i][j];
//                 if (cur == '.') {
//                     continue;
//                 }
//                 int cur_int = cur - '1';
//                 // 根据行和列号对应到的区域编号
//                 int area_index = (i / 3) * 3 + j / 3;
//                 if (row_check[i][cur_int] == 1 || col_check[j][cur_int] == 1 || area_check[area_index][cur_int] == 1) {
//                     // cout << i << endl;
//                     // cout << j << endl;
//                     // cout << cur_int << endl;
//                     // cout << row_check[i][cur_int] << endl;
//                     // cout << col_check[j][cur_int] << endl;
//                     // cout << area_check[area_index][cur_int] << endl;
//                     return false;
//                 }
//                 row_check[i][cur_int] = 1;
//                 col_check[j][cur_int] = 1;
//                 area_check[area_index][cur_int] = 1;
//             }
//         }
//         return true;
//     }
// };



// 位运算,数位哈希
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> col_check(9, 0);
        vector<int> row_check(9, 0);
        vector<int> area_check(9, 0);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char cur = board[i][j];
                if (cur == '.') {
                    continue;
                }
                int cur_int = 1 << (cur - '1');
                // 根据行和列号对应到的区域编号
                int area_index = (i / 3) * 3 + j / 3;
                if ((row_check[i] & cur_int) != 0 || (col_check[j] & cur_int) != 0 || (area_check[area_index] & cur_int) != 0) {
                    return false;
                }
                row_check[i] |= cur_int;
                col_check[j] |= cur_int;
                area_check[area_index] |= cur_int;
            }
        }
        return true;
    }
};
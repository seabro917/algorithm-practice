// leetcode 289
// 位运算,int有32位,因为原输入矩阵的元素值只会取0或者1,所以只会占用最低位的一位,用第二位记录下一个状态
// https://leetcode.cn/problems/game-of-life/solutions/182495/c-wei-yun-suan-yuan-di-cao-zuo-ji-bai-shuang-bai-b/?envType=study-plan-v2&envId=top-interview-150
class Solution {
private:
    int count_neighbors(vector<vector<int>>& board, int x, int y) {
        // 八个衔接的位置坐标
        int directions[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
        int count = 0;
        for (int i = 0; i < 8; i++) {
            int cur_x = x + directions[i][0];
            int cur_y = y + directions[i][1]; 
            // 边界值,直接跳过
            if (cur_x < 0 || cur_x >= board.size() || cur_y < 0 || cur_y >= board[0].size()) {
                continue;
            }
            // 用LSB记录当前状态,用LSB的更高一位(从右向左第二位)记录下一状态,所以只要当前状态(LSB)是1,那么就count++
            if ((board[cur_x][cur_y] & 1) == 1) {
                count++;
            }
        }
        return count;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {    
                // 当前位置的邻近八个位置的元素为1的个数
                int temp_count = count_neighbors(board, i, j);

                cout << temp_count << endl;
                if (board[i][j] == 1) {
                    // 当前状态是1,下一个状态也是1的情况,也就是要把从右向左第二位更新为1
                    if (temp_count == 2 || temp_count == 3) {
                        // LSB记录当前状态,LSB+1的位置记录下一状态
                        // 这一步就是把LSB+1的位置更新为1
                        // board[i][j] = board[i][j] | (1 << 1);
                        board[i][j] |= 2;
                    }
                    // 当前状态是1,下一个状态变为0的情况不需要操作,因为遍历完board之后要再右移动一位,1就直接变成0了.
                }
                else {
                    // 当前状态是0,下一个状态变为1的情况
                    if (temp_count == 3) {
                        // 同样,将LSB+1的位置更新为1
                        // board[i][j] = board[i][j] | (1 << 1);
                        board[i][j] |= 2;
                    }
                    // 和上面的情况类似，当前状态为0，下一个状态也为0的情况不需要操作
                }
            }
            
        }
        // 最后要返回的是下一个状态,也就是LSB+1位置的值,所以右位移一位
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
};

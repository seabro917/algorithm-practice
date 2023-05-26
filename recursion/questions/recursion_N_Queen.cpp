#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
private:
    vector<vector<string>> result;
    void backtracking(int n, int row, vector<string> chessboard)
    {
        // 最后一层（最后一行）已经遍历完毕，则回收结果，注意row是从0开始的，所以这里表示所有行都已经遍历完毕。
        if (n == row)
        {
            result.push_back(chessboard);
            // return;
        }
        for (int column = 0; column < n; column++)
        {
            if (isValid(chessboard, row, column, n))
            {
                chessboard[row][column] = 'Q';
                backtracking(n, row + 1, chessboard);
                chessboard[row][column] = '.';
            }
        }
    }
    bool isValid(vector<string> chessboard, int row, int column, int n)
    {
        // column检查
        for (int i = 0; i < row; i++)
        {
            if (chessboard[i][column] == 'Q')
            {
                return false;
            }
        }
        // 写对角线只用检测右上（45°）和左上（135°）即可，因为主循环是从上往下，下面的Q还未被放置，只用检测当前位置上方即可。
        // 45°检查
        for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        // 135°检查
        for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chessboard[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        result.clear();
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        backtracking(n, 0, chessboard);
        return result;
    }
};
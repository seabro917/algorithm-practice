// leetcode 200
class Solution {
private:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向, x方向加1或者减1，y方向加1或者减1
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
                cout << 'n' << endl;
        // 考虑当前点的相邻四个方向
        for (int i = 0; i < 4; i++) {
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) {
                continue;
            }
            // 如果这个点也是岛屿，那么因为他和输入的结点相邻，我们必须把他标记成visited，这样在主函数里面就不会再被记录一次
            if (grid[next_x][next_y] == '1' && !visited[next_x][next_y]) {
                visited[next_x][next_y] = true;
                dfs(grid, visited, next_x, next_y);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 只有第一次造访的岛屿才会使res增加
                if (grid[i][j] == '1' && !visited[i][j]) {
                    res++;
                    visited[i][j] = true;
                    // 标记和当前岛屿相邻的其他点
                    dfs(grid, visited, i, j);
                }
            }
        }
        return res;
    }
};
// leetcode 1020
// 实际上就是求不到达边界的岛屿的面积。
// 可以从边界出发，边界只要为1，那么就对这个点进行bfs或者dfs，把这个点以及和这个点相邻的为1的点都淹没成0
// 遍历完所有边界之后那么剩下来依旧为1的点就是内部呗完全包围的点了,直接再对grid进行一次遍历,对值为1的点进行计数即可.
class Solution {
private:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    void bfs(vector<vector<int>>& grid, int x, int y) {
        queue<pair<int, int>> que;
        que.push({x, y});
        // 只有在边界处值为1的点才会进到bfs函数中,所以一进来直接淹没掉
        grid[x][y] = 0;
        while (!que.empty()) {
            pair<int, int> cur = que.front();
            que.pop();
            int cur_x = cur.first;
            int cur_y = cur.second;
            for (int i = 0; i < 4; i++) {
                int next_x = cur_x + dir[i][0];
                int next_y = cur_y + dir[i][1];
                if (next_x < 0 || next_y < 0 || next_x >= grid.size() || next_y >= grid[0].size()) {
                    continue;
                }
                // 找到了相临值也为1的点,直接淹没
                if (grid[next_x][next_y] == 1) {
                    que.push({next_x, next_y});
                    grid[next_x][next_y] = 0;
                }
                if (x == 9 && y == 9 && i == 1) {
                cout << "here" << endl;
            }
            }
        }
    } 
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;

        // 左右两个边界开始向中间遍历
        for (int i = 0; i < m; i++) {
            // 在边界处的值为1的点,那么就要进行bfs把它以及与它相邻的点都淹没了
            if (grid[i][0] == 1) {
                bfs(grid, i, 0);
            }
            if (grid[i][n - 1] == 1) {
                cout << i << endl;
                cout << n - 1 << endl;
                bfs(grid, i, n - 1);
            }
        }

        // 上下两个边界向中间遍历
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                bfs(grid, 0, j);
            }
            if (grid[m - 1][j] == 1) {
                bfs(grid, m - 1, j);
            }
        }

        // 最后处理完之后对整个grid里值为1的点再进行一次计数即可.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};


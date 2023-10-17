// leetcode 695
// 实际就是岛屿问题在遍历的时候加上一个计数器。
class Solution {
private:
    int area;
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<pair<int, int>> que;
        que.push({x, y});
        // visited[x][y] = true;
        // area++;
        while(!que.empty()) {
            pair cur = que.front(); 
            que.pop();
            int cur_x = cur.first;
            int cur_y = cur.second;
            for (int i = 0 ;i < 4; i++) {
                int next_x = cur_x + dir[i][0];
                int next_y = cur_y + dir[i][1];
                if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) {    
                    continue;
                }
                if (!visited[next_x][next_y] && grid[next_x][next_y] == 1) {
                    visited[next_x][next_y] = true;
                    area++;
                    que.push({next_x, next_y});
                }
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(m, false));
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    area = 1;
                    visited[i][j] = true;
                    bfs(grid, visited, i, j);
                    result = max(result, area);
                }
            }
        }
        return result;
    }
};
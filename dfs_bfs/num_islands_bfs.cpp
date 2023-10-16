// leetcode 200
// bfs 解法 --> 联想二叉树的层序遍历，完全一样
// 岛屿问题的核心思想就是把所有的位置都标记一下是否访问过，如果访问过那么直接跳过，未访问过且grid为1的则计数
// 计数完之后要将这个计数点周围的grid为1的位置也都标记为访问过(相邻的岛屿)
class Solution {
private:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向, x方向加1或者减1，y方向加1或者减1
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        queue<pair<int, int>> que;
        // visited[x][y] = true;
        que.push({x, y});
        while (!que.empty()) {
            pair<int, int> cur = que.front();
            que.pop();
            int cur_x = cur.first;
            int cur_y = cur.second;
            for (int i = 0; i < 4; i++) {
                int next_x = cur_x + dir[i][0];
                int next_y = cur_y + dir[i][1];
                // 越界，直接跳过，考虑下一种相邻点情况
                if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) {
                    continue;
                }
                if (!visited[next_x][next_y] && grid[next_x][next_y] == '1') {
                    que.push({next_x, next_y});
                    visited[next_x][next_y] = true;
                }
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
                if (!visited[i][j] && grid[i][j] == '1') {
                    res++;
                    visited[i][j] = true;
                    // 将这个位置与其相邻的岛屿都标记为访问过
                    bfs(grid, visited, i, j);
                }   
            }
        }
        return res;
    }
};
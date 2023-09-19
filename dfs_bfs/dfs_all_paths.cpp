// leetcode 797
// 回溯基础题 其实就是dfs
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void dfs(vector<vector<int>>& graph, int node) {
        if (node == graph.size() - 1) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < graph[node].size(); i++) {
            path.push_back(graph[node][i]);
            dfs(graph, graph[node][i]);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0);
        return res;
    }
};
// leetcode 22
// https://labuladong.github.io/algo/di-san-zha-24031/bao-li-sou-96f79/hui-su-sua-89170/
class Solution {
private:
    vector<string> res;
    string path = "";
    // left和right代表的是剩余可以使用的左括号和右括号数目
    // 递归的任何时候如果出现剩余可用的左括号数目大于剩余可用的右括号数目，那么此刻即是不满足条件的，可以直接return到上一层。
    void backtracking(int left, int right, string& path, vector<string>& res) {
        if (left > right) {
            return;
        }
        if (left < 0 || right < 0) {
            return; 
        }
        // 左右括号全部用完，找到一组符合条件的结果
        if (left == 0 && right == 0) {
            res.push_back(path);
            return;
        }
        
        // 放置左括号
        path.push_back('(');
        backtracking(left - 1, right, path, res);
        path.pop_back();

        // 放置右括号
        path.push_back(')');
        backtracking(left, right - 1, path, res);
        path.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        backtracking(n, n, path, res);
        return res;
    }
};
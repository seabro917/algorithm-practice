// leetcode 240
// 从一个角开始搜索
// https://leetcode.cn/problems/search-a-2d-matrix-ii/?envType=study-plan-v2&envId=selected-coding-interview
// 如果选择左上或者右下的话每次就不知道该怎么走了,所以选择另一个对角线的角
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size() - 1;
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                j--;
            }
            else {
                i++;
            }
        }  
        return false;
    }
};
// leetcode 1465
// 最难的地方居然是数值类型转换...
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int horizontalMaxDiff = horizontalCuts[0];
        int verticalMaxDiff = verticalCuts[0];
        for (int i = 0; i < horizontalCuts.size() - 1; i++) {
            horizontalMaxDiff = max(horizontalCuts[i + 1] - horizontalCuts[i], horizontalMaxDiff); 
        }
        for (int i = 0; i < verticalCuts.size() - 1; i++) {
            verticalMaxDiff= max(verticalCuts[i + 1] - verticalCuts[i], verticalMaxDiff); 
        }
        cout << horizontalMaxDiff << endl;
        cout << verticalMaxDiff << endl;
        return ((long long)horizontalMaxDiff * (long long)verticalMaxDiff) % (long long)(1e9 + 7);
    }
};
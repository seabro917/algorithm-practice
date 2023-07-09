#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 先将两个数组排序，以便于之后用小的饼干优先喂饱小的，尽可能把大的留到最后去喂饱大的。
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0;
        for (int i = 0; i < s.size(); i++){
            // 这里一定要先判断当前遍历小孩数组的指针是否越界（都不能放在&&之后作为第二个判断 不然会报错...）
            if (index < g.size() && s[i] >= g[index]){
                index++;
            }
        }
        return index;
    }
};
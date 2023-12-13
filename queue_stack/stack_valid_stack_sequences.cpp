// leetcode 946
// https://leetcode.cn/problems/validate-stack-sequences/solutions/2362056/946-yan-zheng-zhan-xu-lie-mo-ni-qing-xi-wpxi6/?envType=study-plan-v2&envId=selected-coding-interview
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int j = 0;
        for (int i = 0; i < pushed.size(); i++) {
            stk.push(pushed[i]);
            while (!stk.empty() && stk.top() == popped[j]) {
                stk.pop();
                j++;
            }
        }
        return stk.empty();
    }
};
// leetcode 1944
// 一眼单调栈
// 关键在于当一个元素他的下一个元素比他高的时候,那么他的结果就加1,并且出栈
// 这是因为，位置i的元素一旦遇到第一个右边比他高的元素(假设下标为j),那么j位置的元素就是他最后一个能看到的了,j位置之后所有的元素都会被位置j的元素挡住,位置i的元素不可能看得到
//      ----> 其实就是"寻找下一个更高温度",找到了下一个更高温度,那么当前元素在看到下一个更高温度之后也就到此为止了
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> stk;
        vector<int> res(heights.size(), 0);
        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[i] > heights[stk.top()]) {
                res[stk.top()]++;
                stk.pop();
            } 
            if (!stk.empty()) {
                res[stk.top()]++;
            }  
            stk.push(i);
        }
        return res;
    }
};
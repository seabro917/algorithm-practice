class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> my_stack;
        vector<int> res(temperatures.size(), 0);
        my_stack.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            while (!my_stack.empty() && temperatures[i] > temperatures[my_stack.top()]) {
                res[my_stack.top()] = i - my_stack.top();
                my_stack.pop();
            }
            my_stack.push(i);
        }
        return res;
    }
};
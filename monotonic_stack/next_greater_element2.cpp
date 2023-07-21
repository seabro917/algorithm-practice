class Solution {
public:
    // 既然你环形了，那我就把你重复一次，对扩大之后的数组求和之前同样的操作，最后求完之后再只取前一半的即可。
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 元素全部初始化为-1。
        vector<int> res(2*nums.size(), -1);
        // 重复一次输入数组。
        vector<int> temp(nums.begin(), nums.end());
        nums.insert(nums.end(), temp.begin(), temp.end());
        // 单调栈。
        stack<int> my_stack;

        for (int i = 0; i < nums.size(); i++) {
            while (!my_stack.empty() && nums[i] > nums[my_stack.top()]) {
                // 这里是保存数值了，不是之前温度那题保存下标偏移。 
                res[my_stack.top()] = nums[i];
                my_stack.pop();
            }
            my_stack.push(i);
        }

        res.resize(nums.size() / 2);
        return res;
    }
};
class Solution {
private:
    // 构建一个单调队列，保证队列里的数据呈单调递减，数值最大的永远在头部。
    class MyQueue{
    public:
        deque<int> que;
        void pop(int val){
            // 如果经过一次滑动，移除掉的元素大小正好等于最大值，说明移除掉的正好是最大值。
            if (!que.empty() && val == que.front()){
                que.pop_front();
            }
        }
        // 为了保证单调性。
        void push(int val){
            while (!que.empty() && val > que.back()){
                que.pop_back();
            }
            que.push_back(val);
        }

        int front(){
            return que.front();
        }

    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MyQueue my_que;
        // 将输入数组的前k个数据先导入到队列中，作为初始数据。
        for (int i = 0; i < k; i++){
            my_que.push(nums[i]);
        }
        res.push_back(my_que.front());
        for (int i = 1; i < nums.size() - k + 1; i++){
            my_que.pop(nums[i - 1]);
            my_que.push(nums[i + k - 1]);
            res.push_back(my_que.front());
        }
        return res;
    }
};
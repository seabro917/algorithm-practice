// leetcode 239
// 单调队列写法
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






// leetcode 239
// priority queue 写法
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 记录两个值,一个是元素值,一个是下标index.
        // 后面需要通过判断index是否在当前窗口内来判断当前堆顶的元素(最大值)能不能被取到
        // 不过有点好奇,优先队列里面元素类型是pair的时候是自动默认以pair的first元素排序吗...
        priority_queue<pair<int, int>> que;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            que.push({nums[i], i});
        }
        res.push_back(que.top().first);
        for (int i = k; i < nums.size(); i++) {
            que.push({nums[i], i});
            // 当前窗口的下标是[i - k, k]如果此时堆顶的元素的对应下标小于i - k,说明它不在窗口内,
            // pop出去然后继续看下一个栈顶元素在不在,直到找到符合在窗口内的堆顶元素
            while (que.top().second < i - k + 1) {
                que.pop();
            }
            res.push_back(que.top().first);
        }
        return res;
    }
};
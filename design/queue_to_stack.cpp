class MyStack {
public:
    queue<int> que;
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        // 先减一下为了之后循环正好到尾端的那个元素。
        size--;
        while (size-- != 0){
            // 将头部的元素再次加入到队列的尾部。
            que.push(que.front());
            que.pop();
        }   
        int res = que.front();
        que.pop();
        return res;
    }
    
    int top() {
        // 这居然有函数直接调用尾部的值，无敌啦。
        return que.back();
    }
    
    bool empty() {  
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
class MyQueue {
private:
    stack<int> stack_in;
    stack<int> stack_out;
public:
    MyQueue() {
    
    }
    
    void push(int x) {
        stack_in.push(x);
    }
    
    int pop() {
        if (!stack_out.empty()){
            int res = stack_out.top();
            stack_out.pop();
            return res;
        }
        else{
            while (!stack_in.empty()){
                int temp = stack_in.top();
                stack_in.pop();
                stack_out.push(temp);
            }
            int res = stack_out.top();
            stack_out.pop();
            return res;
        }
    }
    
    int peek() {
        int temp = this->pop();
        // 这里要注意不是this->push()，因为我们相当于是要还原现场，是从stack_out最上方弹出去的，所以要放回这个栈的最上方，而不是stack_in的最上方。
        stack_out.push(temp);
        return temp;
    }
    
    bool empty() {
        return stack_in.empty() && stack_out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// leetcode 155
// 难得官方题解的动画做得不错...
// https://leetcode.cn/problems/min-stack/solutions/242190/zui-xiao-zhan-by-leetcode-solution/?envType=study-plan-v2&envId=top-interview-150
class MinStack {
public:
    stack<int> stk;
    // 维护一个辅助栈,和真正保存数据的栈一起push和pop数据,但是保证栈顶一直都是最小值,这样要检索最小值直接调用pop()即可
    stack<int> stk_min;
    MinStack() {
        // 先push一个以便于后面比较
        stk_min.push(INT32_MAX);
    }
    
    void push(int val) {
        stk.push(val);
        // 将较小的push进去,这种push方式其实变相记录了每一个最小值在栈中出现的位置,保证了弹出操作的时候一致性
        stk_min.push(min(val, stk_min.top()));
    }
    
    void pop() {
        stk.pop();
        stk_min.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        // 辅助栈栈顶一直放的是最小值
        return stk_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 注意栈里面存放的一直是数字，遍历的tokens是字符串，而不是字符。
        stack<int> my_stack;
        // RPN计算的规则就是由栈规定的，如果是数字则存入栈，如果是运算符则取出栈顶两个数字进行计算，并且将计算的结果再压回栈中。
        for (int i = 0; i < tokens.size(); i++){
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                // 取出栈顶的两个数字
                int num_1 = my_stack.top();
                my_stack.pop();
                int num_2 = my_stack.top();
                my_stack.pop();
                int temp_res = 0;
                // 注意运算顺序。
                if (tokens[i] == "+") temp_res = num_2 + num_1;
                if (tokens[i] == "-") temp_res = num_2 - num_1;
                if (tokens[i] == "*") temp_res = num_2 * num_1;
                if (tokens[i] == "/") temp_res = num_2 / num_1;
                my_stack.push(temp_res);
            }
            else{
                my_stack.push(stoi(tokens[i]));
            }
        }
        int res = my_stack.top();
        return res;
    }
};
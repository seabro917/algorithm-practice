class Solution {
private:
 char Leftof(char c){
    if (c == ')'){
        return '(';
    }
    else if (c == ']'){
        return '[';
    }
    else{
        return '{';
    }
}

public:
    // 关键点在于只存一个方向的括号，另一半的不要存，只在遍历字符串的时候进行比较即可。
    bool isValid(string s) {
        stack<char> my_stack; 
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                my_stack.push(s[i]);
            } 
            // 输入的字符串还没有到头但是栈已经空了，说明有右括号没被匹配。
            // 当前遍历到的括号和之前的不匹配，也直接false。
            else if(my_stack.empty() || Leftof(s[i]) != my_stack.top()){
                return false;
            }
            else{
                my_stack.pop();
            }
        }
        // 最后遍历完了整个字符串，如果栈也正好空了，说明全都匹配了，如果还有剩余，说明有多余的左边括号。
        return my_stack.empty();
    }
};
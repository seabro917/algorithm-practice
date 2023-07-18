class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> my_stack;
        string res = "";
        for (int i = 0; i < s.size(); i++){
            if (my_stack.empty() || my_stack.top() != s[i]){
                my_stack.push(s[i]);
            }
            else{
                my_stack.pop();
            }
        }
        while (!my_stack.empty()){
            res += my_stack.top();
            my_stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    // 间接寻址。
    private:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
        };
    public:
        // 将中间的结果变量和最后要返回的vector直接定义在public属性里面，这样就不需要在函数内每次传递调用惹。
        vector<string> result;
        string s;
        vector<string> letterCombinations(string digits) {
            // 输入字符串为空的情况。
            if (digits.size() == 0) {
                return result;
            }
            backtracking(digits, 0);
            return result;
        }

        // 答案这里输入的digits设置为传入地址并且设置成const。
        void backtracking(string digits, int index) {
            if(index == digits.size()){
                result.push_back(s);
                return;
            }
            // 获取当前输入string的位置的数字以及对应的字符串，间接寻址。
            int cur_number = digits[index] - '0';
            string cur_letters = letterMap[cur_number];
            for(int i = 0 ; i < cur_letters.size() ; i++){
                s.push_back(cur_letters[i]);
                backtracking(digits, index + 1);
                s.pop_back();
            }
        }
};
// leetcode 2520
class Solution {
public:
    int countDigits(int num) {
        string str = to_string(num);
        int res = 0;
        for (int i = 0; i < str.size(); i++) {
            if (num % (str[i] - '0') == 0) {
                res++;
            }
        }
        return res;
    }
};
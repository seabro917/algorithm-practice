// leetcode 9
class Solution {
public:
    bool isPalindrome(int x) {
        stack<int> st;
        queue<int> que;
        if (x < 0) {
            return false;
        }
        while (x) {
            st.push(x % 10);
            que.push(x % 10);
            x /= 10;
        }
        while (!st.empty()) {
            if (st.top() != que.front()) {
                return false;
            }
            st.pop();
            que.pop();
        }
        return true;
    }
};
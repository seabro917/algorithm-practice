// leetcode 66
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            // 如果当前位置的值为9，那么说明要进位，循环继续
            if (digits[i] == 9) {
                digits[i] = 0;
            }
            // 否则直接当前位置值加一，返回即可
            else {
                digits[i]++;
                return digits;
            }
        }
        // 如果整个for循环都运行了，说明原数组就是99，999，9999这种形式(如果不是的话早就在某一次循环期间return了)
        // 那么返回的值肯定就是100，1000，10000这种
        vector<int> res(digits.size() + 1, 0);
        res[0] = 1;
        return res;
    }
};
// leetcode 670

// // 暴力
// class Solution {
// public:
//     int maximumSwap(int num) {
//         string numStr = to_string(num);
//         int res = num;
//         for (int i = 0; i < numStr.size(); i++) {
//             for (int j = i + 1; j < numStr.size(); j++) {
//                 swap(numStr[i], numStr[j]);
//                 res = max(res, stoi(numStr));
//                 swap(numStr[i], numStr[j]);
//             }
//         }
//         return res;
//     }
// };


// https://leetcode.cn/problems/maximum-swap/solutions/527981/0ms-100-bu-miao-da-wo-by-wang-xue-lei-2-iyz9/
// 贪心
// 从右往左同样的大数,交换靠右边的大数
class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
        // idx[i]记录的是从位置i到numStr的末尾这个子串里,最大的数字出现的idx(同样的最大数字取靠右边的)
        vector<int> idx(numStr.size(), 0);
        int maxIdx = numStr.size() - 1;
        for (int i = numStr.size() - 1; i >= 0; i--) {
            if (numStr[i] > numStr[maxIdx]) {
                maxIdx = i;
            }
            idx[i] = maxIdx;
        }
        // 从左向右遍历,当前位置的idx数组内的对应的值和自身不同的,直接交换并且停止循环
        // 从左向右遍历的顺序体现了另一个贪心:使最左边的小的数和大数交换
        for (int i = 0; i < numStr.size(); i++) {
            if (numStr[i] != numStr[idx[i]]) {
                swap(numStr[i], numStr[idx[i]]);
                break;
            }
        }
        return stoi(numStr);

    }
};
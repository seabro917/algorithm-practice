// leetcode 274
class Solution {
public:
    int hIndex(vector<int>& citations) {
        // 从有可能h的最大值开始一次次递减-->有可能的h的最大值就是数组里面的最大值
        int max_val = *max_element(citations.begin(), citations.end());
        int res = 0;
        for (int i = max_val; i > 0; i--) {
            int num_count = 0;
            // 当前有多少篇文章满足被cite的次数大于等于当前这个h
            for (int j = 0; j < citations.size(); j++) {
                if (citations[j] >= max_val) {
                    num_count++;
                }
            }
            // 当前h满足条件，即有大于等于h篇文章被cite的次数大于等于h次
            if (num_count >= max_val) {
                // 因为要找的是最大的，且外循环是从大到小遍历，所以一旦找到符合条件的直接返回
                res = max_val;
                break;
            }
            // 当前的值不满足条件，放宽条件，递减h
            max_val--;
        }
        return res;
    }
};
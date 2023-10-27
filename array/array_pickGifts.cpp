// leetcode 2558
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            long long temp_max = gifts[0];
            int index_max = 0;
            for (int j = 0; j < gifts.size(); j++) {
                if (gifts[j] > temp_max) {
                    temp_max = gifts[j];
                    index_max = j;
                }
            }
            gifts[index_max] = sqrt(gifts[index_max]);
        }
        for (int i = 0; i < gifts.size(); i++) {
            sum += gifts[i];
        }
        return sum;
        // return (long long)accumulate(gifts.begin(), gifts.end(), 0);
    }
};
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool comparator(vector<int>& a, vector<int>& b){
        // 套路：遇到数值对的排序都先将其中一个升序，另一个降序排列 --> 先优先固定好一个维度，再去考虑另一个维度。
        // 按照身高降序排列，按照k升序排列 --> 抽象地想一下，因为要求的情况是记录之前有多少个人比你“高”，所以肯定高的放前面。
        // 按照k升序排列是因为：e.g., [5, 2]和[5, 3]如果先放[5，3], 那么接下来不管把[5, 2]放在[5, 3]前面还是后面都不满足。
        if (a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> queue;
        sort(people.begin(), people.end(), comparator);
        for (auto p : people){
            queue.insert(queue.begin() + p[1], p);
        }
        return queue;
    }
};
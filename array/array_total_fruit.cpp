// leetcode 904
// 滑动窗口
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int length = 0;
        int left = 0;
        map<int, int> my_map;
        for (int i = 0; i < fruits.size(); i++) {
            my_map[fruits[i]]++;
            // 这里的while是处理不符合条件的情况,之前那个类似的求窗口内的和大于等于target的最小窗口的while是处理符合条件的情况.
            // 一直移除,直到满足条件
            while (my_map.size() > 2) {
                map<int, int>::iterator it = my_map.find(fruits[left]);
                it->second--;
                if (it->second == 0) {
                    my_map.erase(it);
                }
                left++;
            }
            length = max(length, i - left + 1);
        cout << left << endl;
        }
        return length;
    }
};

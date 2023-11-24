// leetcode 380
// https://labuladong.github.io/algo/di-yi-zhan-da78c/shou-ba-sh-48c1d/chang-shu--6b296/
// 主要是要考虑到几个操作的复杂度要求,C++里面的unordered_map和unordered_set都是可以做到O(1)的复杂度来进行增删和查找：https://programmercarl.com/%E5%93%88%E5%B8%8C%E8%A1%A8%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html#%E5%B8%B8%E8%A7%81%E7%9A%84%E4%B8%89%E7%A7%8D%E5%93%88%E5%B8%8C%E7%BB%93%E6%9E%84
// 主要是考虑最后一个“O(1)时间复杂度内以同等概率获得随机元素”
class RandomizedSet {
public:
    // 用vector记录所有数据
    vector<int> data;
    // 每个数据和他在vector内的index的对应关系
    unordered_map<int, int> valToIndex;
    RandomizedSet() {
        // // 用vector记录所有数据
        // vector<int> data;
        // // 每个数据和他在vector内的index的对应关系
        // unordered_map<int, int> valToIndex;
    }
    
    bool insert(int val) {
        if (valToIndex.count(val)) {
            return false;
        }
        // 原来vector内没有这个元素，加入到vector的末尾，并且记录index
        else {
            valToIndex[val] = data.size();
            data.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if (!valToIndex.count(val)) {
            return false;
        }
        // 交换所要删除的元素的位置和vector最后一个位置，然后直接从末尾pop出去即可
        // 记得要先把index保存并且交换一下
        else {
            int index = valToIndex[val];
            // 我们要把需要删除的元素放到vector的末尾，那么原先末尾的元素的index要被改变成要删除的元素他在vector内的index
            valToIndex[data.back()] = index;
            swap(data[index], data.back());
            data.pop_back();
            // 删除这个元素在对应map里面的index记录
            valToIndex.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return data[rand() % data.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


// leetcode 2336
// unordered_set用多了真的会忘记set会本身维持里面的元素有序...
class SmallestInfiniteSet {
private:
    set<int> smaller_vals;
    // 一开始指向1
    int pointer = 1;
public:
    SmallestInfiniteSet() {

    }
    
    int popSmallest() {
        // 如果这个有序的set不为空,那么说明有比当前的pointer指向的数据要小的元素在,而set又是有序的,所以弹出set内第一个元素
        if (!smaller_vals.empty()) {
            int val = *smaller_vals.begin();
            smaller_vals.erase(val);
            return val;
        }
        // 如果这个有序的set为空,说明当前pointer指向的就是最小值
        pointer++;
        return pointer - 1;
    }
    
    void addBack(int num) {
        // 如果要加入的元素小于当前pointer,那么要把这个元素加入有序的set内,如果大于当前的pointer,那么说明要加入的数据本身就已经存在了,不需要进行操作.
        if (num < pointer) {
            smaller_vals.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
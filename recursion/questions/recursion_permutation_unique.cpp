class Solution {
  public:
    vector<vector<int> > permuteUnique(vector<int>& num) {
        vector<vector<int>> result;
        // 第一次是从初始位置开始。
        allpermute(num, 0, result);

        // 逃课写法，直接调用C++的sort和unique去重。
        // 相比无重复元素的全排列只多了这两行。
        // unique返回的是不重复元素的最后一个位置
        // erase(a, b)是删掉数组里面a到b位置的元素
        // 综上 这两行实现了去重
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        
        return result;
    }


    void allpermute(vector<int>& num, int position,
                    vector<vector<int>>& result) {
        // 从数组的position位置开始全排列。
        if (position == num.size() - 1) {
            result.push_back(num);
            return;
        }
        for (int i = position ; i < num.size() ; i++) {
            swap(num[position], num[i]);
            allpermute(num, position + 1, result);
            // 恢复初始状态 --> 还原现场。
            swap(num[position], num[i]);
        }
    }


    void swap(int& a, int& b) {
        int temp = 0;
        temp = b;
        b = a;
        a = temp;
    }
};






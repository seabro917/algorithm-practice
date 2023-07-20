class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st; 
        vector<int> next_large_nums2(nums2.size(), 0);
        vector<int> res(nums1.size(), -1);
        unordered_map<int, int> umap;
        // 先将nums1的每个元素对应的下标记录一下。
        for (int i = 0; i < nums1.size(); i++) {
            umap[nums1[i]] = i;
        }

        // 找到nums2这个大数组每个元素对应的下一个比他大的元素的下标偏移（下一个更高温度那题）。
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) { 
                next_large_nums2[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        // 再次遍历nums2，看看每个元素出没出现在nums1中(借助之前的map判断)
        for (int i = 0; i < nums2.size(); i++) {
            // 当前元素出现在nums1中，那么我们就需要记录结果，可以用==1判断是因为题目说了没有重复元素。
            // 第二个判断条件是因为如果之前得到的next_large_nums2[i]等于0说明nums中之后不存在比nums2[i]大的元素，按照题目这时候应该返回-1。
            if (umap.count(nums2[i]) == 1 && next_large_nums2[i] != 0) {
                // 通过map找到这个当前这个元素在nums1中的下标位置，即umap[nums2[i]]。
                // 注意next_large_nums2[i]表示的是nums2中在nums2[i]之后第一个比nums2[i]大的元素相对于i的偏移量。
                res[umap[nums2[i]]] = nums2[i + next_large_nums2[i]];
            }
        }
        return res;
    }
};
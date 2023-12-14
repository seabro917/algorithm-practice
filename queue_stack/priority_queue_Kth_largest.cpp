// leetcode 215
// 优先队列解法
class Solution {
public:
    // 维护一个size为k的小顶堆,保存nums中最大的k个元素,最后堆顶的元素就是答案
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        for (int i = 0; i < nums.size(); i++) {
            // 堆内元素不足k个,可以直接加入,或者说如果当前元素大于堆顶元素,那么也加入,反正后面会pop掉最小的元素,不用担心堆内元素超过k个.
            if (que.size() < k || nums[i] > que.top()) {
                que.push(nums[i]);
            }
            // 堆内超过k个元素了,将堆顶元素(最小的那个)弹出
            if (que.size() > k) {
                que.pop();
            }
        }
        return que.top();
    }
};


// leetcode 215
// 基于快速排序思想的快速选择
// 每次递归排完一次之后,当前这一层递归的pivot所在的位置就在最终拍好的数组里固定了,
// 如果某一轮递归排完后正好pivot所在的下标等于k,那么此时的pivot就是要求的元素
// 同时在具体实现的时候,可以不用每轮pivot两边都排,排一边就可以了

// 没写出来......
class Solution {
private:
    // 返回当前这层递归排序之后,pivot的下标
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= pivot) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && nums[right] <= pivot) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right) {
            return left;
        }
        if (left < right) {
            int pivot_index = partition(nums, left, right);
        }
        // cout << pivot_index << endl;
        for (auto n : nums) {
            cout << n << ' ' ;
        }
        cout << endl;
        // 在当前pivot_index的左侧找
        if (pivot_index > nums.size() - k) {
            return quickSelect(nums, left, pivot_index - 1, k);
        }
        // 在当前pivot_index的右侧找
        else if (pivot_index < nums.size() - k) {
            return quickSelect(nums, pivot_index + 1, right, k);
        }
        return nums[pivot_index];
    }
public:
    // 维护一个size为k的小顶堆,保存nums中最大的k个元素,最后堆顶的元素就是答案
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
        
    }
};
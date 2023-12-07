// leetcode 287
// 等效成环形链表寻找入口节点
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        // 不能先写while,因为一开始slow和fast都是0,至少要两个都先跑起来再说...
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);
        slow = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};
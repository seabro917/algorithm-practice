// leetcode 80
// 快慢双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        if (nums.size() == 1) {
            return 1;
        }
        bool first_duplicate = true;
        for (int fast = 1; fast < nums.size(); fast++) {
            // 如果相同了，那么判读一下是不是第一次相同。
            if (nums[slow] == nums[fast]) {
                // 如果是第一次相同，那么可以赋值过去，然后把flag反转，保证之后相同的不被赋值过去
                if (first_duplicate) {
                    slow++; 
                    nums[slow] = nums[fast];
                    first_duplicate = false;
                }
                // 既然不是第一次相同了，那么就删除了
                else {
                    continue;
                }
            }
            // 遇到不同的了，那么就直接赋值，并且把flag设置成true.
            else {
                slow++; 
                nums[slow] = nums[fast];
                first_duplicate = true;
            }
        }
        return slow + 1;
    }
};


// 简洁写法，直接就是如果当前待检测位置的值和不等于已检测前一个位置即可
// 类似的，最多三个相等四个相等的都是这个道理
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};

// leetcode 167
// 双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            // 因为原数组有序,那么每次判断左右指针对应的元素的和和target的大小关系,并且移动对应指针即可
            if (numbers[left] + numbers[right] < target) {
                left++;
            }
            else if (numbers[left] + numbers[right] > target) {
                right--;
            }
            else {
                break;
            }
        }
        vector<int> res;
        res.push_back(left + 1);
        res.push_back(right + 1);
        return res;
    }
};
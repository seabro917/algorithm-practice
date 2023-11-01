// leetcode 11
// 双指针 和接雨水一样考虑短板啊
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; 
        int right = height.size() - 1;
        int res = (right - left) * min(height[left], height[right]);
        while (left < right) {
            // 移动短板 不能移动长板 
            // 因为移动短板一格还有可能新获得的面积更大，但是要是移动长板，那么新获得的面积一定更小
            if (height[left] < height[right]) {
                left++;
                res = max(res, (right - left)*min(height[left], height[right]));
            }
            else {
                right--;
                res = max(res, (right - left)*min(height[left], height[right]));
            }
        }
        return res;
    }
};
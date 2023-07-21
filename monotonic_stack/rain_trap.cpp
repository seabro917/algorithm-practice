class Solution {
public:
    int trap(vector<int>& height) {
        // 考虑每行的单调栈解法。
        stack<int> my_stack;
        int sum = 0;

        // 先把第一个元素直接压栈。
        my_stack.push(0);
        for (int i = 1; i < height.size(); i++) {
            if (height[my_stack.top()] > height[i]) {
                my_stack.push(i);
            }
            else if (height[my_stack.top()] == height[i]) {
                // 因为出现相邻的位置高度相同时，是用右边的最新的一个进行后续可盛放水的计算。
                my_stack.pop();
                my_stack.push(i);
            }
            else {
                while (!my_stack.empty() && height[my_stack.top()] < height[i]) {
                    int bottom = height[my_stack.top()];
                    // cout << bottom << endl;
                    my_stack.pop();
                    // 考虑当前遍历位置为1的情况，所以要加入栈不为空的条件。
                    if (!my_stack.empty()) {
                        // 注意这里已经pop过一次了。
                        int width = i - my_stack.top() - 1;
                        // 还是要考虑短板，即求个min。
                        int height_ = min(height[i], height[my_stack.top()]) - bottom;
                        sum += width * height_;
                    }
                }
                my_stack.push(i);
            }
        }
        return sum;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        // 考虑每个列的双指针
        // 分别记录height中每个位置它左边和右边最高的数值(包括当前位置)
        // 包括当前位置是因为，计算当前位置的雨水值的时候，当前位置左右最高值中较小的那个是短板(bottleneck)
        // 然后短板减去当前位置(列)的height就是当前位置可以盛放的雨水体积
        // 但是如果当前列的height比bottleneck还要高的话，那么这个位置一定盛的水为0
        // 所以综上直接把这个逻辑放在了计算当前位置左右最大值的逻辑里，即：当前位置的height也要考虑。
        vector<int> left_max(height.size(), 0);
        vector<int> right_max(height.size(), 0);
        int sum = 0;

        // 第一个位置和最后一个位置一定不能放水，所以直接分别赋值为height[0]和height[height.size()-1]
        // 这样最后计算第一个位置和最后一个位置盛放雨水的时候计算短板和当前位置的height的差直接就是0。
        left_max[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            // 当前位置的height[i]也参与到比较当中。
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        right_max[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            // 当前位置的height[i]也参与到比较当中。
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        for (int i = 0; i < height.size(); i++) {
            // min(left_max[i], right_max[i]) - height[i] 最小值一定为0。
            // 因为考虑的是每个列，所以宽度就是1，直接计算即可。
            sum += min(left_max[i], right_max[i]) - height[i];
        }
         return sum;
    }
};
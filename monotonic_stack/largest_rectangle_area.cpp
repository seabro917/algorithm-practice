class Solution {
public:
    // 双指针解法的关键在于找到当前位置左边右边 第 一 个 比当前位置高度低的位置
    //     ----> 这个和接雨水那题的双指针解法正好相反，而且那里是找的 最 大 值，这里找的是 第 一 个。 
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        vector<int> left_first_lower(heights.size());
        vector<int> right_first_lower(heights.size());
        
        // 我觉得其实这里用了一点贪心，只要你当前位置往左往右看，你隔壁的比你都高，那你就可以毫无顾虑地并且你也应该拓展自己的宽度。
        // (有大佬在我旁边我不用担心他们的高度不够帮我构成矩形，我自己tm就是那个短板，做自己的短板，只要我自己是短板那么别人就别想当那个短板来托我后腿)。
        // 所以要找到当前位置左边和右边第一个比我高度要矮的，说明到这个位置我就不能抱大腿了，想再继续构成矩形的话不能再任性地把自己的高度当作高了
        //         -----> 因为这个比的高度比我低了，想继续构造矩形，他是短板了，得把他的高度当作高了--> 但是我想抱大腿，所以这是个边界(简单地说就是不带你玩)。
        // 注意这里第一个位置的初始化，等下要考。

        // 更新22/07/2023：这里这个步骤tm要求左边和右边第一个低于当前元素的下标，不就是每日温度那题的单调栈吗...意思是这里没用单调栈这样写，动态规划？
        left_first_lower[0] = -1;
        for (int i = 1; i < heights.size(); i++) {
            // 先看看你背靠背的这哥们儿是不是就已经比你低了，如果是那就直接保存了。
            int t = i - 1;
            // 如果你隔壁哥们儿比你高，好家伙，可以抱大腿了，不过想再贪心一点，看看隔壁哥们儿他第一个不能抱的短板在哪儿。
            // 这里涉及到一个死循环的问题，如果left_first_lower数组第一个元素设置成0，那么就有可能会一直死循环。
            // 比如：height数组前两个元素为3，2.这样i=1的时候就会一直死循环，所以这里直接用-1表示当前位置之前的值都比当前位置高。
            // 注意等号也是可以取到的，因为等于的话还是可以构成矩形。
            while (t >= 0 && heights[t] >= heights[i]) {
                // 这里是while是因为，你看你隔壁哥们儿比你高了对吧，那他不能抱大腿的第一个那个哥们儿(第一个比他小的)说不定还是比你大呢?
                // 比如你是4，你哥们儿是100，你哥们儿第一个比他小的是高度为99，虽然不及你哥们儿，但是给你抱抱大腿也足够了。这样一次次while循环，就能找到第一个不能给你抱大腿的短板。
                // 简单的说就是，比你小的肯定比你哥们小，但是比你哥们儿小的，不一定比你小，所以这里是check你哥们儿的那个短板 ----> 相当于是剪枝了，而不是一个个检查。
                // 这里可以再想一想，这tm和KMP的next数组构建里面j指针的赋值方式不也是一样吗？(但是背后的思路不一样) 
                t = left_first_lower[t];
            }
            left_first_lower[i] = t;
        }

        // 同样，找到每个元素右边第一个比他低的元素下标。
        right_first_lower[heights.size() - 1] = heights.size();
        for (int i = heights.size() - 2; i >= 0; i--) {
            int t = i + 1;
            while (t <= heights.size() - 1 && heights[t] >= heights[i]) {
                t = right_first_lower[t];
            }   
            right_first_lower[i] = t;
        }

        // 主循环
        for (int i = 0; i < heights.size(); i++) {
            // 从这里可以看出来上述两个数组第一个元素和最后一个元素初始化的作用。
            // 例如，当i=0的时候，假设heights[1] > heights[0]，那么按照right_first_lower[0] = 1, left_first_lower[0] = -1计算出来的宽度正好是1，即heights[0]没有人给他抱大腿，正好符合我们的预期。
            int width = right_first_lower[i] - left_first_lower[i] - 1;
            // 当前位置heights[i]就是短板(做自己的短板)。
            int area = heights[i] * width;
            res = max(area, res);
        }
        return res;
    }
};


class Solution {
public:
    // 单调栈解法，其实处理逻辑和接雨水一模一样只是单调栈里面元素的递增递减性反了一下，而且这里要对原输入数组预处理一下。
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<int> st;
        // 在原数组的开头和尾部分别增加0是为了考虑并且处理原输入数组为单调递增或者单调递减的情况。
        heights.insert(heights.begin(), 0); // 数组头部加入元素0
        heights.push_back(0); // 数组尾部加入元素0
        st.push(0);

        // 第一个元素已经入栈，从下标1开始
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] > heights[st.top()]) { 
                st.push(i);
            } else if (heights[i] == heights[st.top()]) { 
                st.pop(); 
                st.push(i);
            } else { 
                while (!st.empty() && heights[i] < heights[st.top()]) { 
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int left = st.top();
                        int right = i;
                        int w = right - left - 1;
                        int h = heights[mid];
                        result = max(result, w * h);
                    }
                }
                st.push(i);
            }
        }
        return result;
    }
};

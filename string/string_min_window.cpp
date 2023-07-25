// https://www.nowcoder.com/practice/c466d480d20c4c7c9d322d12ca7955ac?tpId=295&tqId=670&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param S string字符串 
     * @param T string字符串 
     * @return string字符串
     */
    string minWindow(string S, string T) {
        // write code here
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int min_len = INT32_MAX;
        int match = 0;
        int start = 0;
        int left = 0;
        int right = 0;

        // 将T需要的字符导入map中。
        for (auto t: T) {
            need[t]++;
        }

        // 第一个while移动右边指针，在窗口中加入字符
        while (right < S.size()) {
            // char cur_right = S[right];
            // 如果加入的这个字符在T中，则记录更新map
            // 这里一定要用count...不能用if(need[cur_right]>0)来判断一个key是否存在，因为有可能一个key不存在内存分配的值是一个随机数，也可能大于0.
            if (need.count(cur_right)) {
                cout << need.size() << endl;
                window[cur_right]++;
                // 如果这个字符已经达到需求了，则match++，
                // 当match达到need这个map的size，也就是说T中所有字符需求都被满足了，那么我们就可以进入下一个while，依次移动左边指针移除字符，看看是否还满足条件。
                // 注意只有==会记录更新match，不然的话比如S中是{XXXXXX...},T{XYZ}，这种情况会更新三次，而实际上窗口中只有一个X。
                // 而且这个判断必须放在外层判断里面，不然的话遇到不存在于need中的字符，match也会更新。
                if (need[cur_right] == window[cur_right]) {
                    match++;
                }
            }
            right++;
            // 已经满足T字符需求，开始依次移除元素，看看移除之后是否还是能够满足条件，如果可以的话，更新最小滑动窗口，不可以的话，则跳出当前while循环回到外循环，继续移动右指针加入字符。
            while (match == need.size()) {
                cout << "here" << endl;
                if (right - left < min_len) {
                    min_len = right - left;
                    // 更新起点。
                    start = left;
                }
                char cur_left = S[left];
                if (need.count(cur_left)) {
                    window[cur_left]--;
                    if (window[cur_left] < need[cur_left]) {
                        match--;
                    }
                }
                left++;
            }
        }
        // cout << start << endl;
        // cout << min_len << endl;
        return min_len == INT32_MAX ? "" : S.substr(start, min_len);
    }
};
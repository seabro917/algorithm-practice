class Solution {
private:
    static void reverse_(string& s, int a, int b){
        for (int i = a, j = b; i < j; i++, j--){
            swap(s[i], s[j]);
        }
    }

    static void removeSpace(string& s){
        int fast_ptr = 0;
        int slow_ptr = 0;
        // 删除字符串开始的所有空格。
        while (s[fast_ptr] == ' '){
            fast_ptr++;
        }

        // 删除词语之间多余的空格。
        for (; fast_ptr < s.size(); fast_ptr++){
            // 注意这个判断条件，这里保证了词语之间只有一个空格被就地保存。
            if (fast_ptr - 1 > 0 && s[fast_ptr] == s[fast_ptr - 1] && s[fast_ptr] == ' '){
                continue;
            }
            else{
                s[slow_ptr++] = s[fast_ptr];
            }
        }

        // 删除字符串末尾的所有空格，这里有两种情况，上一条判断已经保证了词语间只有一个空格，也保证了如果字符串最后最多只有一个空格。
        // 考虑两种情况,最后有没有空格,并且截取字符串.
        // 注意上一条判断最后slow_ptr最后还++了一下,所以最后存入的数据点是s[slow_ptr],要判断的也就是这个数据点.
        if (slow_ptr -1 > 0 && s[slow_ptr - 1] == ' '){
            s.resize(slow_ptr - 1);
        }
        else{
            s.resize(slow_ptr);
        }
    }
public:
    string reverseWords(string s) {
        // 先反转整体
        reverse_(s, 0, s.size() - 1);
        cout << s << endl;
        // 删除多余空格
        removeSpace(s);
        cout << s << endl;
        // 反转每个单词
        int bound = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' '){
                reverse_(s, bound, i - 1);
                bound = i + 1;
            }
            // 最后的一个单词也要反转,这里逻辑直接单独处理了.
            if (i == s.size() - 1){
                reverse_(s, bound, s.size() - 1);
            }
        }
        return s;
    }
};
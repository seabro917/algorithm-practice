class Solution {
private:
    static void getNext(int* next, string& s){
        next[0] = 0;
        // 定位模式串尾端的指针。
        int j = 0;
        for (int i = 1; i < s.size(); i++){
            while (j - 1 > 0 && s[j] != s[i]){
                j = next[j - 1];
            }
            if (s[j] == s[i]){
                j++;
            }   
            next[i] = j;
        }
        
    }
public:
    // 主要就是要知道最长相同前后缀所不包含的子串就是最小重复子串，然后判断整个字符串长度能不能被这个找到的子串的长度整除。
    bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        getNext(next, s);
        if (s.size() == 1){
            return false;
        }
        // for (auto v : next){
        //     cout << v << endl;
        // }
        // 直接判断整个字符串s的最长相同前后缀。
        // 第二个判断条件是为了考虑例如输入字符串为 "ab"这样的情况
        if ((s.size() % (s.size() - next[s.size() - 1])) == 0 && next[s.size() - 1] != 0){
            return true;
        }
        return false;
    }
};
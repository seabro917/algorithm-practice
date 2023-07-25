// https://www.nowcoder.com/practice/28eb3175488f4434a4a6207f6f484f47?tpId=295&tqId=732&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295
// https://www.nowcoder.com/practice/28eb3175488f4434a4a6207f6f484f47?tpId=295&tqId=732&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295
class Solution {
private:
    string findPrefix(string a, string b) {
        string res;
        int size = min(a.size(), b.size());
        int i = 0;
        while (i < size && a[i] == b[i]) {
            res += a[i];
            i++;
        }
        return res;
    }
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        // write code here
        if (strs.size() == 0) {
            return "";
        }
        string res = strs[0];
        string temp;
        // 以第一个字符串为标准，剩下的所有都和他比较。
        string standard = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            temp = findPrefix(standard, strs[i]);
            // 取两者之中长度较小的那个。
            res = temp.size() > res.size() ? res : temp;
        }
        return res;
    }
};
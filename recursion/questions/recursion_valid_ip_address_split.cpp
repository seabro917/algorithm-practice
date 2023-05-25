#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> result; // 放已经回文的子串
    void backtracking (string& s, int startIndex, int dotNum) {
        // 这里用三个dot作为终止条件，在终止判断条件里面判断第四段子字符串是否符合，如果符合则返回，不符合则不返回呗。
        if (dotNum == 3) {
            if(isValidIP(s, startIndex, s.size()-1)){
                result.push_back(s);
            }
            else{
                return;
                // break;
            }
        }
        for (int i = startIndex; i < s.size(); i++) {
            // 当前取到的子字符串是符合规则的ip地址(的一段)。
            if(isValidIP(s, startIndex, i)){
                s.insert(s.begin()+i+1, '.');
                dotNum++;
                // 这里的下一层递归是从i+2开始，因为插入了一个“,”
                backtracking(s, i + 2, dotNum);
                dotNum--;
                s.erase(s.begin()+i+1);
            }else{
                // 若当前子字符串不符合规定，则直接结束掉而不是continue，因为当前的i如果都不符合了，那么再继续截取i+1的子字符串肯定更不符合。
                break;
            }
        }
    }

    // 判断是否符合合法ip地址的规定。
    bool isValidIP(string& s, int start, int end) {
        // 这个是用于判断最后一个子字符串是否为空，为空则返回false（会有空的情况是因为i+2）.
        if(start >= s.size()){
            return false;
        }
        // 存在非数字字符。
        for(int i = start; i < end ; i++){
            if(s[i] > '9' || s[i] < '0'){
                return false;
            }
        }
        // 当前子字符串是以0开头的情况。
        if(s[start] == '0' && start != end){
            return false;
        }
        // 当前子字符串代表的数字大于255的情况。
        int temp_sum = 0;
        for(int i = start; i <= end ; i++){
            temp_sum = temp_sum * 10 + (s[i] - '0'); 
            if(temp_sum > 255){
                return false;
            }
        }
        return true;
    }
public:　
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        backtracking(s, 0, 0);
        return result;
    }
};
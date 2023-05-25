#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        stringPermutaion(str, 0, result);

        // 和有重复元素的全排列一样,这里也是逃课写法...直接调用C++的sort和unique排序+去重.
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }

    void stringPermutaion(string &str, int position, vector<string> &result){
        if(position == str.length()-1){
            result.push_back(str);
            return;
        }
        for(int i = position ; i < str.length() ; i++){
            charSwap(str[position], str[i]);
            stringPermutaion(str, position+1, result);
            charSwap(str[position], str[i]);
        }

    }

    void charSwap(char &i, char &j){
        char temp_ = j;
        j = i;
        i = temp_;
    }

};
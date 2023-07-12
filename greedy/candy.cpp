#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candyArray(ratings.size(), 1);
        // 右规则，正向遍历，只往当前位置之前的看！保持一致！不要好高骛远！
        for (int i = 1; i < ratings.size(); i++){
            if (ratings[i] > ratings[i - 1]){
                candyArray[i] = candyArray[i - 1] + 1;
                // candyArray[i]++;
            }
        }
        // 左规则，反向遍历，同样，保持一致，只看当前遍历位置之前的情况，不要看更远的，那样会和之前上面考虑的右规则弄混淆。
        for (int j = ratings.size() - 2; j >= 0; j--){
            if (ratings[j] > ratings[j + 1]){
                // 这里需要取max是因为例如如下情况：当第一个右规则已经执行完毕，假设我们得到的candyArray = [..., 3, 4, 1,...]，我们对此执行这里的左规则。
                // 如果我们执行这条判断的时候只考虑candyArray[j] = candyArray[j + 1] + 1，那么得到的candyArray就变成了：[...,3, 2, 1,...]。
                // 即：打破了我们之前已经实施好的右规则，所以我们需要在执行左规则时候保证之前已经执行完毕的右规则不被打破。
                // 同样的，如果我们是先执行的左规则，那么在右规则的循环体判断条件中也要有类似的语句，重点就在于保证在实施一个规则的时候要保证之前已经实施完毕的规则不被打破。
                //     ---->一致性！
                candyArray[j] = max(candyArray[j], candyArray[j + 1] + 1);
            }
        }
        int res = 0;
        for (int i = 0; i < candyArray.size(); i++){
            res += candyArray[i];
        }
        return res;
    }
};

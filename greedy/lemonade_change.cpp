#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_count = 0;
        int ten_count = 0;
        for (int i = 0; i < bills.size(); i++){
            if (bills[i] == 5){
                five_count++;
            }
            else if (bills[i] == 10){
                if (five_count > 0){
                    five_count--;
                    ten_count++;
                }
                else{
                    return false;
                }
            }
            else if (bills[i] == 20){
                if (five_count > 0 && ten_count > 0){
                    five_count--;
                    ten_count--;
                }
                // 这里不能写if，因为如果写if的话不管上一条判断有没有进入判断体，这一条判断都会被检测 --> 总不能我都找过你一次钱了还要我接着再找一次吧？
                // 但是我们想要的结果是优先使用面值为10的纸币，尽可能把5的节省下来。
                else if (five_count > 2 && ten_count == 0){
                    five_count = five_count - 3; 
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
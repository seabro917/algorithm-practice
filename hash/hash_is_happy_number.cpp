#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

// 计算过程中一旦出现重复的sum，则直接返回false，因为之后的操作只会是之前的重复-->无限循环。
class Solution {
public:
    int getSumSquare(int n){
        int sum = 0;
        while(n != 0){
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        std::set<int> sum_set;
        while(true){
        int sum = getSumSquare(n);
        if(sum == 1){
            return true;
        }
        // 当前求到的和不存在于set中.
        if(sum_set.find(sum) == sum_set.end()){
            sum_set.insert(sum);
        }
        // 一旦当前求到的sum已经存在于set中，则说明计算已经进入死循环，直接返回false.
        else{
            return false;
        }
        n = sum;
        }
    }
};
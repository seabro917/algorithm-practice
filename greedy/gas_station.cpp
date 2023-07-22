#include <iostream>
#include <vector>

using namespace std;

// 图解法。
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int minVal = 0;
        int start_point = 0;
        for (int i = 0; i < gas.size(); i++){
            sum += gas[i] - cost[i];
            if (sum < minVal){
                // 如果当前这个加油站是最低点，那么应该把下一个加油站当作起点。
                // 要把亏损最严重的一步放在最后一步走，等待之前所有步数的累加来给你这个最差的垫背 --> 一群大佬拖着你走 :p
                start_point = i + 1;
                minVal = sum;
            }
        }
        // sum(gas)-sum(cost)都小于0了，那么一切都白搭。
        if (sum < 0){
            return -1;
        }
        return start_point == gas.size() ? 0 : start_point;
    }
};


// 贪心：类似的代码，不同的理解方式。
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank = 0;
        int start_point = 0;
        int total_sum = 0;
        for (int i = 0; i < gas.size(); i++){
            tank += gas[i] - cost[i];
            total_sum += gas[i] - cost[i];
            // 从当前位置到当前位置之后第一个使tank变成小于0的位置之间都不可能是起点。
            //     ---->因为你想你以当前位置为起点的时候，这段距离之间任意一点的tank肯定大于0，如果从这段距离之间任意一个点开始，说明你把那个点的tank设为0（起点tank为0），那肯定到这个点的时候更小于0了啊。
            if (tank < 0){
                tank = 0;
                start_point = i + 1;
            }
        }
        if (total_sum < 0){
            return -1;
        }
        return start_point;
    }
};
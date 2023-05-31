#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int result;
        std::map<int, int> val_map;
        for(int i = 0; i < numbers.size(); i++){
            if(val_map.find(numbers[i]) == val_map.end()){
                val_map.insert(pair <int, int> (numbers[i], 1));
            }
            else{
                val_map.find(numbers[i])->second = val_map.find(numbers[i])->second + 1;
            }
        }
        for(std::map<int, int>::iterator itr = val_map.begin(); itr != val_map.end(); itr++){
            if(itr->second > numbers.size() / 2){
               result = itr->first;
               break;
            }
        }
        return result;
    }
};
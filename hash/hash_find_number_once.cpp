#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        std::map<int, int> val_map;
        vector<int> result;
        for(int i = 0; i < array.size(); i++){
            if(val_map.find(array[i]) == val_map.end()){
                val_map.insert(pair <int, int> (array[i], 1));
            }
            else{
                val_map.find(array[i])->second = val_map.find(array[i])->second + 1;
            }
        }
        for(std::map<int, int>::iterator itr = val_map.begin(); itr != val_map.end(); itr++){
            if(itr->second == 1){
               result.push_back(itr->first);
            }
        }
        return result;
    }
};
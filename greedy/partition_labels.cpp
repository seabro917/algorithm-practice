#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int lastIndex[26] = {0};
        for (int i = 0; i < s.size(); i++){
            lastIndex[s[i] - 'a'] = i;
        }

        int maxBound = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++){
            maxBound = max(maxBound, lastIndex[s[i] - 'a']);
            if (i == maxBound){
                res.push_back(maxBound - left + 1);
                left = maxBound + 1;
            }
        }
        return res;
    }
};
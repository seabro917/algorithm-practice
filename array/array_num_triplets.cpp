// leetcode 1577
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        // 两个map存储两个数组所有乘积出现的次数
        unordered_map<long long, int> map_1;
        unordered_map<long long, int> map_2; 
        long long res = 0;
        // nums1的任意两个元素乘积出现的次数
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = i + 1; j < nums1.size(); j++) {
                map_1[(long long)1*nums1[i]*nums1[j]]++;
            }
        }
        // 同样的，统计nums2内所有乘积出现的次数
        for (int i = 0; i < nums2.size(); i++) {
            for (int j = i + 1; j < nums2.size(); j++) {
                map_2[(long long)1*nums2[i]*nums2[j]]++;
            }
        }
        // 情况1
        for (int i = 0; i < nums1.size(); i++) {
            res += map_2[(long long)1*nums1[i]*nums1[i]];
        }
        // 情况2
        for (int i = 0; i < nums2.size(); i++) {
            res += map_1[(long long)1*nums2[i]*nums2[i]];
        }
        return res;
    }
};
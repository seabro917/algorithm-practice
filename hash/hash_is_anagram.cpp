// #include <iostream>
// #include <vector>
// #include <set>
// #include <map>
// using namespace std;

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         // 两个存储对应字符串内每个字母出现次数的map.
//         std::map<char, int> map_1;
//         std::map<char, int> map_2;
//         // 将第一个字符串的字母压入map.
//         for(int i = 0 ; i < s.length(); i++){
//             if (map_1.count(s[i]) == 0){
//                 map_1.insert(pair <char, int> (s[i], 1));
//             }
//             else{
//                 std::map<char, int>::iterator itr_find = map_1.find(s[i]);
//                 // second代表的就是value值，first代表的是key的值。(注意要用迭代器)
//                 itr_find->second = itr_find->second + 1;
//             }
//         }   
//         // 将第二个字符串的字母压入map.
//         for(int i = 0 ; i < t.length(); i++){
//             if (map_2.count(t[i]) == 0){
//                 map_2.insert(pair <char, int> (t[i], 1));
//             }
//             else{
//                 std::map<char, int>::iterator itr_find = map_2.find(t[i]);
//                 // second代表的就是value值，first代表的是key的值。(注意要用迭代器)
//                 itr_find->second = itr_find->second + 1;
//             }
//         }  
//         // 如果字母种类不同则直接返回false.
//         if(map_1.size() != map_2.size()){
//             return false;
//         }
//         // 本来C++标准库的map的key值就是排好序的，所以直接比较是否相等即可。
//         for (std::map<char, int>::iterator it_1 = map_1.begin(), it_2 = map_2.begin(); it_1 != map_1.end() && it_2 != map_2.end() ; it_1++, it_2++){
//             if(it_1->first != it_2->first || it_1->second != it_2->second){
//                 return false;
//             }
//         }
//         return true;
//     }
// };


// 直接只用一个数组代表26个字母，遍历第一个字符串的时候对应字母位置++，结束之后遍历第二个字符串的时候对应位置--，最后如果得到的数组所有位置都为0，则返回true.
class Solution_ {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
                return false;
            }
        }
        // record数组所有元素都为零0，说明字符串s和t是字母异位词
        return true;
    }
};
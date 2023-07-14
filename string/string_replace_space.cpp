// class Solution {
// public:
//     string replaceSpace(string s) {
//         string res;
//         for (int i = 0; i < s.size(); i++){
//             if (s[i] == ' '){
//                 res.push_back('%');
//                 res.push_back('2');
//                 res.push_back('0');
//             }
//             else{
//                 res.push_back(s[i]);
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (auto c : s){
            if (c == ' '){
                res.push_back('%');
                res.push_back('2');
                res.push_back('0');
            }
            else{
                res.push_back(c);
            }
        }
        return res;
    }
};
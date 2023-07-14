class Solution {
private:
    static void swap_(char& a, char& b){
        char temp;
        temp = b;
        b = a;
        a = temp;
    }
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--){
            swap_(s[i], s[j]);
        }
    }
};
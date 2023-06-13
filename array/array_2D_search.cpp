class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int column = array[0].size()-1;
        int row = 0;
        if(array[0].size()==0){
            return false;
        }
        while(row < array.size() && column >= 0){
            if(array[row][column] < target){
                row++;
            }
            else if(array[row][column] > target){
                // 说明当前行已经不用再继续寻找了，往下层寻找。
                column--;
            }
            else{
                return true;
            }
        }
        return false;        
    }
};




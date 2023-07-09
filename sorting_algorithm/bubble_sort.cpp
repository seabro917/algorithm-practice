#include <iostream>
using namespace std;



void BubbleSort(int arr[], int len){
    for(int i = 0 ; i < len ; i++){
        for(int j = 0 ; j < len - i ; j++){
            // 交换对应元素。
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int array_1[10] = {9,2,1,2,3,5,8,5,7,1};
    cout << "Before sort: " << endl;
    for(int i = 0 ; i < 10 ; i++){
        cout << array_1[i] << " "; 
    }
    BubbleSort(array_1, 10);
    cout << "After sort: " << endl;
    for(int i = 0 ; i < 10 ; i++){
        cout << array_1[i] << " "; 
    }
    

}
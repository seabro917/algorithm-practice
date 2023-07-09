#include <iostream>
#include <vector>
using namespace std;


int Partition(int arr[], int start, int end){
    int pivot = arr[start];
    while (start < end){
        // 注意判断条件还有等于号。
        while (arr[end] >= pivot){
            end--;
        }
        // 交换
        arr[start] = arr[end];
        arr[end] = pivot;
        // 这里要加上start < end是因为一个while循环结束后有可能双指针已经重合，应当退出循环
        //（上一个的while循环不需要这个判断，因为当前这个while循环结束后会优先判断最外面的while循环条件）。
        while (start < end && arr[start] <= pivot){
            start++;
        }
        arr[end] = arr[start];
        arr[start] = pivot;
    }
    // 最后start和end应该是相等的
    return start;
}



void QuickSort(int arr[], int start, int end){
    if (start < end){
        int pivot = Partition(arr, start, end);
        // 排列基准之前的数组
        QuickSort(arr, start, pivot - 1);
        // 排列基准之后的数组
        QuickSort(arr, pivot + 1, end);
    }
}

int main(){
    int array_1[10] = {9,2,1,2,3,5,8,5,7,1};
    cout << "Before sort: " << endl;
    for (int i = 0 ; i < 10 ; i++){
        cout << array_1[i] << " "; 
    }
    QuickSort(array_1, 0, 9);
    cout << "After sort: " << endl;
    for (int i = 0 ; i < 10 ; i++){
        cout << array_1[i] << " "; 
    }
    

}
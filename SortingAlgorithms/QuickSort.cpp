#include<bits/stdc++.h>
using namespace std;

void QuickSort(int arr[],int start, int end){
    if(start < end){
        int pivot = arr[end];
        int i  = start;
        int j = i-1;
        while(i < end && j < i){
            if(arr[i] <= pivot){
                j++;
                swap(arr[j],arr[i]);
            }
            i++;
        }
        QuickSort(arr,start,j-1);
        QuickSort(arr,j+1,end);
    }
    return;
}

void PrintArray(int *arr,int size){
    for(int i = 0;i<size;i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main(){
    int arr[] = {2,4,1,6,8,5,3,7};
    PrintArray(arr,8);
    QuickSort(arr,0,7);
    PrintArray(arr,8);
    return 0;
}
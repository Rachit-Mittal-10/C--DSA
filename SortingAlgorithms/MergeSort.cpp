#include<bits/stdc++.h>
using namespace std;

void Merge(int *left_arr, int *right_arr, int *arr,int size,int nL, int nR){
    int i = 0, j = 0, k = 0;
    while(i<nL && j<nR && k<size){
        if(left_arr[i] <= right_arr[j]){
            arr[k] = left_arr[i];
            i++;
        }else{
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while(i<nL && k<size){
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while(j<nR && k<size){
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void MergeSort(int *arr,int size){
    if(size < 2){
        return;
    }
    int mid = size/2;
    int lsize = mid;
    int rsize = size - mid;
    int left[lsize];
    int right[rsize];
    int i;
    for(i = 0;i<mid;i++){
        left[i] = arr[i];
    }
    for(i=mid;i<size;i++){
        right[i-mid] = arr[i];
    }
    MergeSort(left,lsize);
    MergeSort(right,rsize);
    Merge(left,right,arr,size,lsize,rsize);
}

void PrintArray(int *arr,int size){
    for(int i = 0;i<size;i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main(){
    int arr[] = {2,4,1,6,8,5,3,7};
    PrintArray(arr,8);
    MergeSort(arr,8);
    PrintArray(arr,8);
    return 0;
}
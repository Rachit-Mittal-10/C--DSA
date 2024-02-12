#include<bits/stdc++.h>
#include<D:\C++\Print.hpp>
using namespace std;

void InsertionSort(vector<int>& arr, int size){
    if(size <= 1) return;

    int temp = arr[--size];
    int j = size-1;

    InsertionSort(arr,size);

    while((arr[j] > temp) && (j >= 0)){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
}


int main(){
    vector<int> arr = {1,4,5,0,9,8,7,6,2};
    Print(arr);
    InsertionSort(arr,arr.size());
    Print(arr);
    return 0;
}
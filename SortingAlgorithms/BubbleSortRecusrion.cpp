#include<bits/stdc++.h>
#include<D:\C++\Print.hpp>
using namespace std;

void BubbleSort(vector<int>& arr, int size){
    if(size == 1 || size == 0) return;

    for(int i=0;i<size-1;i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    
    BubbleSort(arr,size-1);
}

int main(){
    vector<int> arr {1,4,2,7,6};
    Print(arr);
    BubbleSort(arr,arr.size());
    Print(arr);
    return 0;
}
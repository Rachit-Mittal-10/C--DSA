#include<bits/stdc++.h>
#include<D:\C++\Print.hpp>
using namespace std;


void SelectionSort(vector<int>& arr, int start=0){
    int size = arr.size();

    if(start >= size) return;
    
    int MinIndex = start;
    for(int i = start+1;i<size;i++){
        if(arr[i] < arr[MinIndex]){
            MinIndex = i;
        }
    }
    swap(arr[start],arr[MinIndex]);
    start++;
    SelectionSort(arr,start);
}

int main(){
    vector<int> arr = {1,4,5,0,9,8,7,6,2};
    Print(arr);
    SelectionSort(arr);
    Print(arr);
    return 0;
}
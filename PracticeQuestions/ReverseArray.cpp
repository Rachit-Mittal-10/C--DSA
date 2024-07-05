#include<bits/stdc++.h>
using namespace std;

void ReverseArray(int arr[],int len){
    int start = 0;
    int end = len - 1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void PrintArray(int arr[],int len){
    for(int i=0;i<len;i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main(){
    int arr[] = {1,2,3,4};
    PrintArray(arr,4);
    ReverseArray(arr,4);
    PrintArray(arr,4);
    return 0;
}
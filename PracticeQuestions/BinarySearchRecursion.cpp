#include<bits/stdc++.h>
using namespace std;

// Binary Search through Recursion
bool BinarySearch(int arr[],int start, int end,int key){
    if(start > end) return false;

    int mid = start + ((end-start)/2);

    if(key == arr[mid]) return true;
    else if(key > arr[mid]) BinarySearch(arr,mid+1,end,key);
    else BinarySearch(arr,start,mid-1,key);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << boolalpha << BinarySearch(arr,0,size-1,2) << endl;
    return 0;
}
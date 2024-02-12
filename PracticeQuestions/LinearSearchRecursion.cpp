#include<bits/stdc++.h>
using namespace std;

// Linear Search using Recursion
bool LinearSearch(int arr[],int size,int key){
    if(size <= 0) return false;

    if(key == arr[0]) return true;

    LinearSearch(arr+1,size-1,key);
}

int main(){
    int arr[] = {4,2,1,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << boolalpha << LinearSearch(arr,size,8) << endl;
    return 0;
}
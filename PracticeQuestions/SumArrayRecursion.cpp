#include<bits/stdc++.h>
using namespace std;
/*
Sum of the Array using Recursion 
*/

int SumArray(int arr[],int size){
    if(size == 0){
        return 0;
    }

    if(size == 1){
        return arr[0];
    }

    return (arr[0] + SumArray(arr+1,size-1));
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << SumArray(arr,size) << endl;
    return 0;
}
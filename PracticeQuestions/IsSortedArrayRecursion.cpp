#include<bits/stdc++.h>
using namespace std;

// Check whether the array is sorted or not via Recursion
bool IsSortedArray(int arr[],int size){
    if(size == 1 || size == 0) return true;

    if(arr[0] > arr[1]) return false;
    
    bool ans = IsSortedArray(arr+1,size-1);
    return ans;
}

int main(){
    int Arr[] = {1,2,3,4,5,6,0};
    bool ans = IsSortedArray(Arr,7);
    cout << boolalpha << ans << endl;
    return 0;
}
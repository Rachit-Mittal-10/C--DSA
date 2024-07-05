#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int Arr[],int size, int key){
    int start = 0;
    int end = size-1;
    int mid = start + ((end-start)/2);
    while(start<=end){
        
        /*
        If Start = 2^31-1 and End = 2^31-1
        then Start + End = 2^32-2. This is way outside the range of INT so it might throw the error.
        To counter it, we distribute two among start and end separately.
        Now start/2 and end/2 will always be integer.
        In Case of start and end being odd, It will increase time complexity.
        So We get little clever and write it this way to maintain the complexity.
        */
        
        if(Arr[mid]==key){
            return mid;
        }else if(Arr[mid]>key){
            end = mid - 1;
        }else if(Arr[mid]<key){
            start = mid + 1;
        }
        mid = start + ((end-start)/2);
    };
    return -1;
}

int main(){
    int arr[] = {5,6,8,9,10,11};
    int len = sizeof(arr)/sizeof(arr[0]);
    int Key;
    cin >> Key;
    cout << BinarySearch(arr,len,Key) << endl;
    return 0;
}
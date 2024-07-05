#include<bits/stdc++.h>
using namespace std;

int leftmost(vector<int> &arr,int n,int key){
    int start = 0;
    int end = n - 1;
    int left=-1;
    int mid = start + ((end-start)/2);
    while(start<=end){
        if(arr[mid]==key){
            left = mid;
            end = mid-1;
        }else if(arr[mid]>key){
            end = mid-1;
        }else if(arr[mid]<key){
            start = mid + 1;
        }
        mid = start + ((end-start)/2);
    }
    return left;
}

int rightmost(vector<int> &arr,int n,int key){
    int start = 0;
    int end = n - 1;
    int right=-1;
    int mid = start + ((end-start)/2);
    while(start<=end){
        
        if(arr[mid]==key){
            right = mid;
            start = mid + 1;
        }else if(arr[mid]>key){
            end = start-1;
        }else if(arr[mid]<key){
            start = mid + 1;
        }
        mid = start + ((end-start)/2);
    }
    return right;
}


// 1 2 3 3 3 3 5
// 0 1 2 3 4 5 6  <-- Index


int main(){
    vector<int> arr{1,2,3,3,3,3,5};
    int left = leftmost(arr,7,3);
    int right = rightmost(arr,7,3);
    cout << "left: " << left << endl << "right: " << right << endl;
    return 0;
}
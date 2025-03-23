/* 
todo LeetCode 153: Minimum in Rotated and Sorted Array
: Find the minimum in rotated and sorted array in O(logn) time
: Binary Search Question
*/
#include<vector>
#include<iostream>
using namespace std;
/* 
: We assume that mid is where minimum index is and keep track of minumum element found so far.
: If mid has smaller element then update else move further to decrease subspace

: Important Part is How to update the search space
- 
*/
int BinarySearch(vector<int>& arr){
    int start = 0;
    int end = arr.size()-1;
    int minIndexSofar = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(minIndexSofar == -1){
            minIndexSofar = mid;
        }
        else{
            if(arr[mid] < arr[minIndexSofar]){
                minIndexSofar = mid;
            }
        }
        if(arr[mid] > arr[end]){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return arr[minIndexSofar];
}

int main(void){
    vector<int> arr = {4,5,6,7,0,1,2,3};
    // vector<int> arr = {0,1,2,3,4,5,6,7};
    // vector<int> arr = {3,1,2};
    cout << BinarySearch(arr) << endl; 
}
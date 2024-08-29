/*
* GFG Question Link: https://www.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1
todo: We have given a array which is strictly increasing and then maybe strictly decrease. Find the bitonic point ie max element in array
*/

#include<iostream>
using namespace std;

/*
*Approach Binary Search
- Apply Binary Search to find the maximum element
- Maximum Element would be greater than left and right element
- Edge Cases: mid == n-1 or mid==0
*/

class Solution{
public:
	int findMaximum(int arr[], int n) {
	    // code here
	    int start = 0;
	    int end = n-1;
	    while(start <= end){
	        int mid = start + (end-start)/2;
			if(mid == n-1){
				return arr[mid] > arr[mid-1] ? arr[mid] : arr[mid-1];
			}
			if(mid == 0){
				return arr[mid] > arr[mid+1] ? arr[mid] : arr[mid+1];
			}
	        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
	            return arr[mid];
	        }
	        else if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]){
	            start = mid + 1;
	        }
	        else if(arr[mid] < arr[mid-1] && arr[mid] > arr[mid+1]){
	            end = mid - 1;
	        }
	    }
	    return arr[n-1];
	}
};

int main(void){
    int arr[5] = {5,4,3,2,1};
    int n = 5;
    cout << Solution().findMaximum(arr,n) << endl;
}
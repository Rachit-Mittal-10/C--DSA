/*
* LeetCode Question 33: Search in Rotated Sorted Array
todo: Given the array sorted and rotated, you need to search the element in it.
? Rotated Sorted Array: It is sorted and then rotated clockwise or anticlockwise by k steps.
? 1,2,3,4,5 ====> 4,5,1,2,3
? This is rotated clockwise by 2 steps
*/

#include<vector>
#include<iostream>
using namespace std;

class LinearSearchApproach{
public:
    int search(vector<int>& arr, int target){
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i] == target){
                return i;
            }
        }
        return -1;
    }
};

/*
* Approach: Binary Search with a twist that We need to identify the Sorted part here.
* For left part to be sorted, condition would `arr[start] < arr[mid]`. If this is true then left part is sorted otherwise right part is sorted.
*/
class BinarySearch{
public:
    int search(vector<int>& arr, int target){
        int start = 0;
        int end = arr.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid]==target){
                return mid;
            }
            //* Identifying the sorted Part
            if(arr[start]<=arr[mid]){
                if(target <= arr[mid] && target >= arr[start]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(target >= arr[mid] && target <= arr[end]){
                    start = mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};


int main(void){
    vector<int> array = {7,8,9,1,2,3,4,5,6};
    int target = 5;
    cout << LinearSearchApproach().search(array,target) << endl;
    cout << BinarySearch().search(array,target) << endl;
}
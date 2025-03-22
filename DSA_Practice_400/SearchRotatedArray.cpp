/*
todo: LeetCode 33:: Search in Rotated Array
*/

#include<iostream>
#include<vector>
using namespace std;


class LinearSearchApproach{
public:
    int solve(vector<int>& arr, int target){
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i] == target){
                return i;
            }
        }
        return -1;
    }
};

class BinarySearch{
public:
    int solve(vector<int>& arr, int target){
        int n = arr.size();
        int start = 0;
        int end = n-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] == target){
                return mid;
            }
            if(arr[start] <= arr[mid]){
                // * Left Part Sorted 
                if(target >= arr[start] && target <= arr[mid]){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            else{
                // * Right Part Sorted
                if(target >= arr[mid] && target <= arr[end]){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return -1;
    }
};

int main(void){
    vector<int> arr = {4,5,6,7,1,2,3};
    auto Solution1 = LinearSearchApproach();
    auto Solution2 = BinarySearch();
    cout << Solution1.solve(arr,2) << endl;
    cout << Solution2.solve(arr,2) << endl;
}
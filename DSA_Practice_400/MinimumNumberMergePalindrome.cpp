/* 
todo: Find the minimum number of merge operation required to make the array palindrome
*/
#include<bits/stdc++.h>
using namespace std;

class BruteForceApproach{
public:
    int solve(vector<int>& arr){
        if(arr.size() == 1){
            return 0;
        }
        int start = 0;
        int end = arr.size()-1;
        int mergeOperationCount = 0;
        while(start <= end){
            if(arr[start] == arr[end]){
                start++;
                end--;
                continue;
            }
            else if(arr[start] > arr[end]){
                mergeOperationCount++;
                arr[end-1] += arr[end];
                end--;
                continue;
            }
            else{
                mergeOperationCount++;
                arr[start+1] += arr[start];
                start++;
            }
        }
        return mergeOperationCount;
    }
};

int main(void){
    vector<int> arr1 = {1,4,5,1};
    vector<int> arr2 = {1,4,1,2,7,1};
    vector<int> arr3 = {1};
    auto S = BruteForceApproach();
    cout << "Arr1: " << S.solve(arr1) << endl;
    cout << "Arr2: " << S.solve(arr2) << endl;
    cout << "Arr3: " << S.solve(arr3) << endl;
}
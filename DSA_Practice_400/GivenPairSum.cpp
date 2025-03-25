/* 
todo: Find the pair with sum K in the rotated and sorted array 
*/
#include<bits/stdc++.h>
using namespace std;


class BruteForceSolution{
    /* 
    : Time Complexity: O(N^2)
    : Space Complexity: O(N) just for storing the result.
    */
public:
    vector<pair<int,int>> solve(vector<int>& arr, int target){
        int n = arr.size();
        vector<pair<int,int>> result;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i] + arr[j] == target){
                    result.emplace_back(make_pair(arr[i],arr[j]));
                }
            }
        }
        return result;
    }
};


/* 
11, 15, 6, 8, 9, 10

Target = 16

Assumption: There is only one pair with the given sum

0,5 : 11+10 = 21  => 18 > 16 => r--
0,4: 10+16
*/

class Optimised{
    /* 
    : There could be one more optimisation that Pivot could be find out by Binary Search. See Minimum in Rotated Sorted Array
    */
    int findPivotLinear(vector<int>& arr){
        int i = 0;
        int n = arr.size();
        while(i<n-1){
            if(arr[i] > arr[i+1]){
                break;
            }
            i++;
        }
        return i;
    }
public:
    vector<pair<int,int>> solve(vector<int>& arr, int target){
        int pivot = findPivotLinear(arr);
        int pivot = 
        int n = arr.size();
        int left = (pivot+1)%n;
        int right = pivot;
        vector<pair<int,int>> result;
        while(left != right){
            int sum = arr[left] + arr[right];
            if(sum == target){
                result.push_back(make_pair(arr[left],arr[right]));
                break;
            }
            if(sum > target){
                right = (right-1+n)%n;
            }
            if(sum < target){
                left = (left+1)%n;
            }
        }
        return result;
    }
};

int main(void){
    vector<int> arr = {11, 15, 6, 8, 9, 10};
    // auto S = BruteForceSolution();
    // auto result = S.solve(arr,16);
    auto S = Optimised();
    auto result = S.solve(arr,16);
    for(auto i:result){
        cout << i.first << " " << i.second << endl;
    }
}
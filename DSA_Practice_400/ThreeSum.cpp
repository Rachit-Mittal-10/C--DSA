#include<iostream>
#include<vector>
#include<algorithm>
#include "../Print.hpp"
using namespace std;

class ThreeSum{
/*
: Run a loop after sorting the array
: Two Pointer Approach in a loop to find -nums[i] sum pair

*/
    public:
    vector<vector<int>> solve(vector<int>& arr){
        sort(arr.begin(),arr.end());
        vector<vector<int>> result;
        if(arr[0] > 0){
            return result;
        }
        int n = arr.size();
        for(int i=0;i<n-2;i++){
            if(i>0 && arr[i] == arr[i-1]){
                /* 
                : Skipping Duplicates
                */
               continue;
            }
            int left = i+1;
            int right = n-1;
            while(left < right){
                int currSum = arr[i] + arr[left] + arr[right];
                if(currSum == 0){
                    result.push_back({arr[i],arr[left],arr[right]});
                }
                else if(currSum > 0){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return result;
    }
};

int main(void){
    vector<int> arr = {-2,-1,0,1,2};
    auto result = ThreeSum().solve(arr);
}
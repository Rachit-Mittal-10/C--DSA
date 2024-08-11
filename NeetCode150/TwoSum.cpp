/*
Here we need to return the index of two number which sums to targetSum.
LeetCode Question: 1
*/

// Neccessary Header import
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


/*
Approach: Brute Force
- Run loop from i=0 to n:
    - Run loop from j=i+1 to n:
        - if arr[i] + arr[j] equals target then return {i,j}

Time Complexity: O(N^2)
Space Complexity: O(1)
*/
vector<int> twoSumBrute(vector<int>& nums, int target){
    int n = nums.size();
    vector<int> ans = {-1,-1};
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+ nums[j] == target){
                ans[0] = i;
                ans[1] = j;
            }
        }
    }
    return ans;
}

/*
Approach: Map based
- Initiliase a map. Store the element with their index in this traversed so far.
- Run a loop from i=0 to n:
    - if target-nums[i] present in map then return i,mp[target-nums[i]]
    - otherwise add nums[i] with i to mp. mp[nums[i]] = i;
*/
vector<int> twoSumMap(vector<int>& nums, int target){
    int n = nums.size();
    unordered_map<int,int> mp;
    vector<int> ans = {-1,-1};
    for(int i=0;i<n;i++){
        int otherNum = target - nums[i];
        if(mp.find(otherNum) == mp.end()){
            mp[nums[i]] = i;
        }
        else{
            ans[0] = i;
            ans[1] = mp[otherNum];
            break;
        }
    }
    return ans;
}

int main(void){
    vector<int> arr = {1,2,5,3,9,4};
    int target = 8;
    vector<int> indicesTarget = twoSumMap(arr,target);
    cout << indicesTarget[0] << " | " << indicesTarget[1] << endl;
}
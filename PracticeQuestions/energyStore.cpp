// Link: https://www.geeksforgeeks.org/problems/geek-jump/1
#include<iostream>
#include<map>
#include<vector>
#include<climits>
using namespace std;


// } Driver Code Ends
class Solution {
    map<int, int> energyStore;
    // Memorisation but Test Case-119,120,121 maybe failing due to Segmentation Fault
    // I suspect larger recursive tree
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    int solve(vector<int>& height, int n){
        if(n==0){
            return 0;
        }
        if(energyStore.find(n) != energyStore.end()){
            return energyStore[n];
        }
        int jumpTwo = INT_MAX;
        int jumpOne = solve(height,n-1) + abs(height[n]-height[n-1]);
        if(n>1){
            jumpTwo = solve(height,n-2) + abs(height[n]-height[n-2]);
        }
        int energy = min(jumpOne,jumpTwo);
        energyStore[n] = energy;
        return energy;
    }
    // Tabulation
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    int solveTabulate(vector<int>& height, int n){
        vector<int> dp(n,-1);
        dp[0] = 0;
        for(int i=1;i<n;i++){
            int jumpTwo = INT_MAX;
            int jumpOne = dp[i-1] + abs(height[i]-height[i-1]);
            if(i>1){
                jumpTwo = dp[i-2] + abs(height[i]-height[i-2]);
            }
            dp[i] = min(jumpOne,jumpTwo);
        }
        return dp[n-1];
    }
    // Optimise Space
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    int solveOptimal(vector<int>&height, int n){
        int prev2=0, prev1=0;
        for(int i=1;i<n;i++){
            int jumpTwo = INT_MAX;
            int jumpOne = prev1 + abs(height[i]-height[i-1]);
            if(i>1){
                jumpTwo = prev2 + abs(height[i]-height[i-2]);
            }
            int curr = min(jumpOne,jumpTwo);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
        
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        // return solve(height,n-1);
        return solveOptimal(height,n);
    }
};
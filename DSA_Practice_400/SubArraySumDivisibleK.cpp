#include<bits/stdc++.h>
using namespace std;

class Solution{
    bool isDivisible(int a, int b){
        return (a%b == 0);
    }
    pair<int,pair<int,int>> solveUtil(vector<int>& arr, int K){
        int MAX_LEN = INT_MIN;
        int MAX_SUM = INT_MIN;
        int i=0;
        int n = arr.size();
        int sum = 0;
        pair<int,pair<int,int>> result = {INT_MIN,{-1,-1}};
        while(i<n){
            sum = 0;
            int j=i;
            while(j<n){
                sum += arr[j];
                if(isDivisible(sum,K) && sum > MAX_SUM){
                    MAX_LEN = max(MAX_LEN,j-i+1);
                    MAX_SUM = max(MAX_SUM,sum);
                    result.first = MAX_LEN;
                    result.second.first = i;
                    result.second.second = j;
                }
                j++;
            }
            i++;
        }
        return result;
    }
public:
    int solve(vector<int>& arr, int K){
        return solveUtil(arr,K).first;
    }
};


int main(void){
    vector<int> arr = {2, 7, 6, 1, 4, 5};
    auto S = Solution();
    auto result = S.solve(arr,3);
    cout << result << endl;
    // cout << result.first << " " << result.second.first << " " << result.second.second << endl;
}
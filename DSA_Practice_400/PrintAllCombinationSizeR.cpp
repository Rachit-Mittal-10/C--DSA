#include<bits/stdc++.h>
#include"../Print.hpp"
using namespace std;

class BruteForceApproach{
    /* 
    - Time Complexity: O(n^m)
    - Space Complexity: O(r)
    */
    void solve(vector<int>& arr, int r, int counter, int index, vector<int>& temp, vector<vector<int>>& result){
        if(counter >= r){
            result.push_back(temp);
            return;
        }
        if(index >= arr.size()){
            return;
        }
        if(r - counter > arr.size() - index){
            return;
        }
        temp.push_back(arr[index]);
        solve(arr,r,counter+1,index+1,temp,result);
        temp.pop_back();
        solve(arr,r,counter,index+1,temp,result);
        return;
    }
public:
    vector<vector<int>> solve(vector<int>& arr, int r){
        vector<vector<int>> result;
        if(r > arr.size()){
            return result;
        }
        vector<int> temp = {};
        solve(arr,r,0,0,temp,result);
        return result;
    }
};

int main(void){
    vector<int> arr;
    for(int i=1;i<=4;i++){
        arr.push_back(i);
    }
    auto S = BruteForceApproach();
    auto S1 = S.solve(arr,2);
    Print(S1);
    cout << "Number of Combinations: " << S1.size() << endl;
}
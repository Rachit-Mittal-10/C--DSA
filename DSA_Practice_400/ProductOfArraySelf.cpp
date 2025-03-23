#include<iostream>
#include<vector>
#include "../Print.hpp"
using namespace std;

class LinearSolution{
    void getPrefix(vector<int>& arr, vector<int>& prefix){
        int n = arr.size();
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]*arr[i-1];
        }
    }
    void getSuffix(vector<int>& arr, vector<int>& suffix){
        int n = arr.size();
        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1]*arr[i+1];
        }
    }
    void solve(vector<int>& arr, vector<int>& result){
        int n = arr.size();
        vector<int> suffix(n,1);
        vector<int> prefix(n,1);
        getSuffix(arr,suffix);
        getPrefix(arr,prefix);
        for(int i=0;i<n;i++){
            result[i] = prefix[i]*suffix[i];
        }
    }
public:
    vector<int> solve(vector<int>& arr){
        int n = arr.size();
        vector<int> result(n,0);
        solve(arr,result);
        return result;
    }
};

int main(void){
    vector<int> arr = {1,2,3,4};
    auto result = LinearSolution().solve(arr);
    Print(result);
}
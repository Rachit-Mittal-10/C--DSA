#include<vector>
#include<iostream>
using namespace std;

class LinearSolution{
    void getPrefixArr(vector<int>& arr, vector<int>& prefix, int& n){
        prefix[0] = arr[0];
        for(int i=1;i<n;i++){
            prefix[i] = max(prefix[i-1],arr[i]);
        }
    }
    void getSuffixArr(vector<int>& arr, vector<int>& suffix, int &n){
        suffix[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i] = max(suffix[i+1],arr[i]);
        }
    }
public:
    int solve(vector<int>& arr){
        int n = arr.size();
        vector<int> prefixArr(n,-1);
        vector<int> suffixArr(n,-1);
        getPrefixArr(arr,prefixArr,n);
        getSuffixArr(arr,suffixArr,n);
        int total = 0;
        for(int i=0;i<n;i++){
            if(arr[i] < prefixArr[i] && arr[i] < suffixArr[i]){
                total += min(prefixArr[i],suffixArr[i]) - arr[i];
            }
        }
        return total;
    }
};

int main(void){
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    auto S = LinearSolution();
    cout << S.solve(arr) << endl;
}
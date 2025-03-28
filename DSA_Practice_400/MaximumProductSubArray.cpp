#include<bits/stdc++.h>
using namespace std;

class KadaneAlgorithm{
    /* 
    Compared to maximum sum array we need to maintain the min and max product so far since most negative can become largest when multiplied by negative integer.
    */
public:
    int solve(vector<int>& arr){
        int MAX_PRODUCT = arr[0];
        int MIN_PRODUCT = arr[0];
        int p = 1;
        int n = arr.size();
        int MAX_GLOBAL = INT_MIN;
        while(p<n){
            if(arr[p] < 0){
                swap(MAX_PRODUCT,MIN_PRODUCT);
            }
            MIN_PRODUCT = min(arr[p],arr[p]*MIN_PRODUCT);
            MAX_PRODUCT = max(arr[p],arr[p]*MAX_PRODUCT);
            p++;
            MAX_GLOBAL = max(MAX_PRODUCT,MAX_GLOBAL);
        }
        return MAX_GLOBAL;
    }
};

int main(void){
    vector<int> arr = {2,3,-2,4};
    auto S = KadaneAlgorithm();
    cout << S.solve(arr) << endl;
}
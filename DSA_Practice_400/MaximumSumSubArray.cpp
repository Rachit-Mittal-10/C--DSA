#include<bits/stdc++.h>
using namespace std;

class BruteForceApproach{
public:
    int solve(vector<int>& arr){
        int MAX_SUM = INT_MIN;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += arr[j];
                MAX_SUM = max(MAX_SUM,sum);
            }
        }
        return MAX_SUM;
    }
};

class KadaneAlgorithm{
    /* 
    -2,1,-3,4,-1,2,1,-5,4
    
    */
public:
    int solve(vector<int>& arr){
        int sum = 0;
        int MAX_SUM = INT_MIN;
        int p1 = 0;
        int p2 = 0;
        int n = arr.size();
        while(p1<n){
            sum += arr[p1];
            MAX_SUM = max(sum,MAX_SUM);
            if(sum < 0){
                sum = 0;
            }
            p1++;
        }
        return MAX_SUM;
    }
};

int main(void){
    // vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> arr = {-1};
    auto S = BruteForceApproach();
    auto R = KadaneAlgorithm();
    cout << S.solve(arr) << endl;
    cout << R.solve(arr) << endl;
}
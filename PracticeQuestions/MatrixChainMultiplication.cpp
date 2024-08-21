#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        int n = N-1;
        vector<vector<int>> M(N,vector<int>(N,0));
        int d = 1;
        while(d<n){
            for(int i=1;i<n-d;i++){
                int j = i+d;
                if(j>n){
                    break;
                }
                int mini = INT_MAX;
                for(int k=i;k<j;k++){
                    int cost = M[i][k] + M[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    mini = min(cost,mini);
                }
                M[i][j] = mini;
            }
            d++;
        }
        return M[1][n];
    }
};

int main(){
    int arr[4] = {10,30,5,60};
    Solution S;
    cout << S.matrixMultiplication(4,arr) << endl;
}
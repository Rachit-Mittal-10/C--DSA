/* 
Given is that M*N matrix. Goal is to find the A*B matrix that has mean of element as k(7).
*/
#include<bits/stdc++.h>
using namespace std;

class BruteForceApproach{
    int getMatrixSum(vector<vector<int>>& arr, int rowStart, int colStart, int a, int b){
        int sum = 0;
        for(int i=rowStart;i<rowStart+a;i++){
            for(int j=colStart;j<colStart+b;j++){
                sum += arr[i][j];
            }
        }
        return sum;
    }
public:
    bool solve(vector<vector<int>>& arr, int m, int n, int a, int b, int k){
        int i = 0;
        int j = 0;
        while(i+a < m){
            while(j+b < n){
                int sum = getMatrixSum(arr,i,j,a,b);
                int mean = sum/(a*b);
                if(mean == k){
                    return true;
                }
                j++;
            }
            i++;
        }
        return false;
    }
};

int main(void){
    vector<vector<int>> matrix = {
        {0,1,2,3,4},
        {5,6,7,8,9},
        {10,11,12,13,14},
        {15,16,17,18,19}
    };
    auto result = BruteForceApproach().solve(matrix,matrix.size(),matrix[0].size(),2,3,3);
    cout << boolalpha << result << endl;
}
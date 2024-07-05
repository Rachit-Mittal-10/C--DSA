#include<bits/stdc++.h>
using namespace std;
#include<D:\C++\Print.hpp>

bool BinarySearch2D(vector<vector<int>>& Matrix, int target);

int main(){
    vector<vector<int>> Matrix{
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    Print(Matrix);
    bool answer = BinarySearch2D(Matrix,10);
    cout << boolalpha << answer << endl;
    return 0;
}

// in this, We take 2 Counter for Row and Column and try to find location accordingly.
// Two Pointer Approach to apply Binary Search Logic of reducing search space
bool BinarySearch2D(vector<vector<int>>& Matrix, int target){
    int row = Matrix.size();
    int col = Matrix[0].size();
    int i = 0;  // Couunter for Row
    int j = col - 1;    // Counter for Column
    while(i<row && j > -1){
        if(Matrix[i][j] == target){
            return true;
        }else if(Matrix[i][j] < target){
            i++;
        }else if(Matrix[i][j] > target){
            j--;
        }
    }
    return false;
}
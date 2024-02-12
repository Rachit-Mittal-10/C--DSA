#include<bits/stdc++.h>
using namespace std;
#include<D:\C++\Print.hpp>

bool BinarySearch2D(vector<vector<int>>& Matrix, int target);
// Vector Matrix sorted vertically
int main(){
    vector<vector<int>> Matrix{
        {1,4},
        {2,5}
    };
    Print(Matrix);
    bool answer = BinarySearch2D(Matrix,2);
    cout << boolalpha << answer << endl;
    return 0;
}

bool BinarySearch2D(vector<vector<int>>& Matrix, int target){
    int row = Matrix.size();
    int col = Matrix[0].size();
    int start = 0;
    int end = row*col - 1;
    int mid = start + (end-start)/2;
    int i,j;
    while(start <= end){
        i = mid/col;
        j = mid%col;
        if(Matrix[j][i] == target){
            return true;
        }else if(Matrix[j][i] < target){
            start = mid + 1;
        }else if(Matrix[j][i] > target){
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return false;
}
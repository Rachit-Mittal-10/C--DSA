#include<bits/stdc++.h>
using namespace std;
#include<D:\C++\Print.hpp>

void Rotate(vector<vector<int>> &Matrix);

int main(){
    vector<vector<int>> Matrix{
        {0,1,2,3,4},
        {5,6,7,8,9},
        {10,11,12,13,14},
        {15,16,17,18,19},
        {20,21,22,23,24}
    };
    cout << "Before Rotation" << endl;
    Print(Matrix);
    Rotate(Matrix);
    cout << "After Rotation by 90 ClockWise" << endl;
    Print(Matrix);
    return 0;
}
/*
We would first transpose the matrix then Reverse the Matrix by Column
0 1 2
3 4 5
6 7 8
After Transpose
0 3 6
1 4 7
2 5 8
After Reverse
6 3 0
7 4 1
8 5 2
*/
void Rotate(vector<vector<int>> &Matrix){
    int row = Matrix.size();
    int col = Matrix[0].size();
    //Transpose
    for(int i=0;i<row;i++){
        for(int j=i;j<col;j++){
            swap(Matrix[i][j],Matrix[j][i]);
        }
    }
    //Reverse Logic
    for(int i=0;i<row;i++){
        for(int j=0;j<col/2;j++){
            swap(Matrix[i][j],Matrix[i][col-j-1]);
        }
    }
}

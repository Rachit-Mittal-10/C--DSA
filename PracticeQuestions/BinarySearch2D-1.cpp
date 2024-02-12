#include<bits/stdc++.h>
using namespace std;
#include<D:\C++\Print.hpp>

pair<int,int> BinarySearch2D(vector<vector<int>>& Matrix, int target);
// Vector Matrix sorteed Horizontally
int main(){
    vector<vector<int>> Matrix{
        {0,1,2,3,4},
        {5,6,7,8,9},
        {10,11,12,13,14},
        {15,16,17,18,19},
        {20,21,22,23,24}
    };
    Print(Matrix);
    pair<int,int> answer = BinarySearch2D(Matrix,23);
    cout << "Row: " << answer.first << " Column: " << answer.second << endl;
    return 0;
}

pair<int,int> BinarySearch2D(vector<vector<int>>& Matrix, int target){
    int row = Matrix.size();
    int col = Matrix[0].size();
    int start = 0;
    int end = row*col - 1;
    int mid = start + (end-start)/2;
    pair<int,int> answer(-1,-1);
    int i,j;
    while(start <= end){
        i = mid/col;
        j = mid%col;
        if(Matrix[i][j] == target){
            answer.first = i;
            answer.second = j;
            break;
        }else if(Matrix[i][j] < target){
            start = mid + 1;
        }else if(Matrix[i][j] > target){
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return answer;
}
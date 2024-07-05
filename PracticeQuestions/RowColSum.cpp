#include<bits/stdc++.h>
using namespace std;

void RowSum(int arr[][3],int row,int col);
void ColSum(int arr[][3],int row,int col);
void Print(int arr[][3],int row,int col);


int main(){
    int arr[3][3] = {0,1,2,3,4,5,6,7,8};
    Print(arr,3,3);
    RowSum(arr,3,3);
    ColSum(arr,3,3);
    return 0;
}
// Row Wise Sum
void RowSum(int arr[][3], int row,int col){
    int sum_row;
    for(int i = 0;i<row;i++){
        sum_row = 0;
        for(int j = 0;j<col;j++){
            sum_row += arr[i][j];
        }
        cout << "Row" << i+1 << " "<< sum_row << endl;
    }
}
// Column Wise Sum
void ColSum(int arr[][3],int row, int col){
    int sum_col;
    for(int i=0;i<col;i++){
        sum_col = 0;
        for(int j=0;j<row;j++){
            sum_col += arr[j][i];
        }
        cout << "Col" << i+1 << " " << sum_col << endl;
    }
}

void Print(int arr[][3],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


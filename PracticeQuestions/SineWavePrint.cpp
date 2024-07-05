#include<bits/stdc++.h>
using namespace std;

/*
Code Studio: Print Like a Wave
In this, We need to print the 2D Array in Sine Wave format.
0 1 2
3 4 5
6 7 8
Result: 0 3 6 7 4 1 2 5 8
Approach: Odd Columns had Bottom to Up Traversal of Rows while Even Columns had Up to Bottom Traversal of Rows
*/
void Print(int arr[][3],int row,int col);
void SineWave(int arr[][3], int row, int col);

int main(){
    int arr[3][3] = {0,1,2,3,4,5,6,7,8};
    Print(arr,3,3);
    SineWave(arr,3,3);
    return 0;
}

void SineWave(int arr[][3], int row, int col){
    for(int i = 0; i < col; i++){
        if(i&1){
            // Odd Columns: Bottom to Top
            for(int j = row-1; j > -1;j--){
                cout << arr[j][i] << " ";
            }
        }
        else{
            // Even Columns: Top to Bottom
            for(int j = 0; j<row;j++){
                cout << arr[j][i] << " ";
            }
        }
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

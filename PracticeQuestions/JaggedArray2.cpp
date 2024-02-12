#include<bits/stdc++.h>
using namespace std;
/*
Jagged Array is the type of array where each row had different number of columns.
*/
int main(){
    int rows;
    int*cols = new int[rows];
    cout << "Enter the Number of Rows: ";
    cin >> rows;
    int ** matrix = new int*[rows];
    for(int i=0;i<rows;i++){
        matrix[i] = new int[i+1];
    }
    for(int i=0;i<rows;i++){
        cout << "Enter the Number of Columns: ";
        cin >> cols[i];
        for(int j=0;j<cols[i];j++){
            cin >> matrix[i][j];
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols[i];j++){
            cout <<  matrix[i][j] << " ";
        } cout << endl;
    }
    return 0;
}

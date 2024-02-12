#include<bits/stdc++.h>
using namespace std;

// Matrix Multiplication
void Matrix_Multiplication(int M1[][25],int M2[][25],int M3[][25],int r1,int c1,int r2,int c2){
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            M3[i][j] = 0;
            for(int k=0;k<c1;k++){
                M3[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}


// Printing the Matriz
void PrintMatrix(int arr[][25],int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Matrix Input
void Enter_Data(int Matrix[][25],int row,int column){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cout << "Enter the Element " << i << "-" << j <<": ";
            cin >> Matrix[i][j];
        }
    }
}

int main(){
    
    int firstMatrix[25][25],secondMatrix[25][25],thirdMatrix[25][25];
    int r1,r2,c1,c2;
    
    cout << "Enter the Size of Column for First Matrix: ";
    cin >> c1;
    cout << "Enter the Size of Row for First Matrix: ";
    cin >> r1;
    cout << "Enter the Size of Column for Second Matrix: ";
    cin >> c2;
    cout << "Enter the Size of Row for Second Matrix: ";
    cin >> r2;

    while(c1!=r2){
        cout << "Matrix Multiplication not possible if Row of Second and Column of First aren't equal";
        
        cout << "Enter the Size of Column for First Matrix: ";
        cin >> c1;
        cout << "Enter the Size of Row for First Matrix: ";
        cin >> r1;
        cout << "Enter the Size of Column for Second Matrix: ";
        cin >> c2;
        cout << "Enter the Size of Row for Second Matrix: ";
        cin >> r2;
    }
    cout << "First Matrix:" << endl;
    Enter_Data(firstMatrix,r1,c1);
    cout << "Second Matrix:" << endl;
    Enter_Data(secondMatrix,r2,c2);
    Matrix_Multiplication(firstMatrix,secondMatrix,thirdMatrix,r1,c1,r2,c2);
    cout << "Result Matrix" << endl;
    PrintMatrix(thirdMatrix,r1,c2);
    return 0;
}
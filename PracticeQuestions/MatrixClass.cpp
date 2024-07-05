#include<bits/stdc++.h>
using namespace std;

class __Matrix__{
    private:
        int Matrix[25][25];
        int row, col;
    public:
        void GetMatrix(int r,int c){
            __Matrix__ M;
            row = r;
            col = c;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    cout << "Enter Matrix::" << i+1 << ":" << j+1 << "-";
                    cin >> Matrix[i][j];
                }
            }
        }
        void PrintMatrix(){
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    cout << Matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
        
        __Matrix__ Multiply(__Matrix__ M){
            __Matrix__ M1;
            M1.row = row;
            M1.col = M.col;
            for(int i=0;i<row;i++){
                for(int j=0;j<M.col;j++){
                    M1.Matrix[i][j] = 0;
                    for(int k=0;k<col;k++){
                        M1.Matrix[i][j] += Matrix[i][k] * M.Matrix[k][j];
                    }
                }
            }
            return M1;
        }
};

int main(){
    __Matrix__ M1,M2,M3;
    int r1,c1,r2,c2;
    do{
        cout << "Enter the row of Matrix-A: ";
        cin >> r1;
        cout << "Enter the Column of Matrix-A: ";
        cin >> c1;
        cout << "Enter the row of Matrix-B: ";
        cin >> r2;
        cout << "Enter the Column of Matrix-B: ";
        cin >> c2;
    }while(c1!=r2);

    cout << "::Matrix-A::" << endl;
    M1.GetMatrix(r1,c1);
    cout << "::Matrix-B::" << endl;
    M2.GetMatrix(r2,c2);
    // Multiplication
    M3 = M1.Multiply(M2);
    cout << "::Resultant Matrix::" << endl;
    M3.PrintMatrix();
    return 0;
}
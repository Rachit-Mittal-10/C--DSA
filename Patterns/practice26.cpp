// Dabang Pattern
// Pattern 25
// 1 2 3 4 5 5 4 3 2 1  |1 <---rows
// 1 2 3 4 * * 4 3 2 1  |2
// 1 2 3 * * * * 3 2 1  |3
// 1 2 * * * * * * 2 1  |4
// 1 * * * * * * * * 1  |5
// --------------------
// 1 2 3 4 5 6 7 8 9 10 <----columns
// ---------------
// 1 2 3 4 4 3 2 1  |1
// 1 2 3 * * 3 2 1  |2
// 1 2 * * * * 2 1  |3
// 1 * * * * * * 1  |4

#include<iostream>
using namespace std;

int main(){
    int row;
    cout << "Enter the Row Count: ";
    cin >> row;
    int i = 1;
    while(i<=row){
        int j = 1;
        int val = 1;
        while(j<=2*row){
            if(i+j<=row+1){
                cout << val << " ";
                val++;
            }
            else if(j>=row+1&&j-i>=row){
                val = 2*row - (j - i) - (i-1);
                cout << val << " ";
            }
            else{
                cout << "* ";
            }
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
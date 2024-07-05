// Pattern-24
// 1 2 3 4 5 6 7 <-- column
//       1       |1 <--rows
//     1 2 1     |2
//   1 2 3 2 1   |3
// 1 2 3 4 3 2 1 |4

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
        while(j<=i+3){
            if(i+j<=4){
                cout << "  ";
            }
            else if(j<=4&&i+j<=8){
                cout << val << " ";
                val++;
            }
            else{
                val = row + i - j;
                cout << val << " ";
            }
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
#include<iostream>
using namespace std;
// Pattern-5
// * * * * *
//   * * * *
//     * * *
//       * *
//         *


int main(){
    int row;
    cout << "Enter the Row Count: ";
    cin >> row;

    int i = 0;
    while(i<row){
        int j = 0;
        while(j<row){
            if(j < i){
                cout << "  ";
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
// Pattern-4
//         * 
//       * *
//     * * *
//   * * * *
// * * * * *

#include<iostream>
using namespace std;

int main(){
    int row;
    cout << "Enter the Row Count: ";
    cin >> row;

    int i = 0;
    while(i<row){
        int j = 0;
        while(j<row){
            if(j<row-i-1){
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
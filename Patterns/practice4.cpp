// Pattern-3
// * * * * * 
// * * * *
// * * *
// * *
// *

#include<iostream>
using namespace std;

int main(){
    int row;
    cout << "Enter the Row: ";
    cin >> row;
    int i = 0;
    while(i<row){
        int j = 0;
        while(j<row-i){
            cout << "* ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
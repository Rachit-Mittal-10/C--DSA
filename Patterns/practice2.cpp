/*
Pattern-1
* * * *
* * * *
* * * *
* * * *
*/

#include<iostream>
using namespace std;

int main(){
    int row,col;
    cout << "Enter the Row: ";
    cin >> row;
    cout << "Enter The Col: ";
    cin >> col;
    int i=0;
    while(i<row){
        int j=0;
        while(j<col){
            cout << "* ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
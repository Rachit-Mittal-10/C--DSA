// Pattern-15
// A B C 
// D E F
// G H I

#include<iostream>
using namespace std;

int main(){
    int row;
    cout << "Enter The Row Count: ";
    cin >> row;
    int i = 1;
    int ascii = 65;
    while(i<=row){
        int j=1;
        while(j<=row){
            cout << (char)ascii << " ";
            ascii++;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
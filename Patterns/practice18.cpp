// Pattern-17
// A B C
// A B C
// A B C

#include<iostream>
using namespace std;

int main(){
    int row;
    cout << "Enter The Row Count: ";
    cin >> row;
    int i = 1;
    while(i<=row){
        int j=1;
        int ascii = 65;
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
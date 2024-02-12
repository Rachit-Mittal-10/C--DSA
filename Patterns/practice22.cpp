// Pattern-21
// A 
// B B
// C C C

#include<iostream>
using namespace std;

int main(){
    int row;
    cout << "Enter the Row Count: ";
    cin >> row;

    int i = 1;
    while(i<=row){
        int j = 1;
        int ascii = 65 + i-1;
        while(j<=i){
            cout << (char)ascii << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
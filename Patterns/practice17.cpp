// Pattern-16
// A A A 
// B B B
// C C C

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
            j++;
        }
        ascii++;
        cout << endl;
        i++;
    }
    return 0;
}
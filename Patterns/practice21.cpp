// Pattern-20
// A
// B C
// C D E

#include<iostream>
using namespace std;

int main(){
    int row;
    cout << "Enter The Row Count: ";
    cin >> row;
    int i = 1;
    while(i<=row){
        int j=1;
        while(j<=row){
            int ascii = 65 + i+j-2;
            cout << (char)ascii << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
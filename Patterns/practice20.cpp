// Pattern-19
// A 
// B C
// D E F

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
        
        while(j<=i){
            cout << (char)ascii << " ";
            j++;
            ascii++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
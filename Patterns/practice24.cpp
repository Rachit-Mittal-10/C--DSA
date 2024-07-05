// Pattern-23
// C
// B C
// A B C
#include<iostream>
using namespace std;

int main(){
    int row;
    cout << "Enter the Row Count: ";
    cin >> row;
    int i=1;
    while (i<=row){
        char ch = 'A' + row-i;
        int j =1;
        while(j<=i){
            cout << ch << " ";
            ch++;
            j++;
        }
        cout <<  endl;
        i++;
    }
    
    return 0;
}
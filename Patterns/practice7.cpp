// Pattern - 6
// 1 1 1 
// 2 2 2
// 3 3 3

#include<iostream>
using namespace std;

int main(){
    int row;
    cout << "Enter the Row Count: ";
    cin >> row;
    int i = 1;
    while(i<=row){
        int j = 0;
        while(j<row){
            cout << i << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    
    return 0;
}
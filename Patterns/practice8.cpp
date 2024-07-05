// Pattern-7
// 1 2 3 
// 1 2 3
// 1 2 3
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
            cout << j+1 << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    
    return 0;
}
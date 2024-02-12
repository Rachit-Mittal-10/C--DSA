// Pattern-9
// 9 8 7 
// 6 5 4
// 3 2 1

#include<iostream>
using namespace std;

int main(){
    int row;
    cout << "Enter the Row Count: ";
    cin >> row;
    int i = 1;
    int n=9;
    while(i<=row){
        int j = 0;
        while(j<row){
            cout << n << " ";
            j++;
            n--;
        }
        cout << endl;
        i++;
    }
    
    return 0;
}
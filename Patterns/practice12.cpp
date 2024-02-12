#include<iostream>
using namespace std;
// Pattern-11
// 1 
// 2 2
// 3 3 3
// 4 4 4 4
// 5 5 5 5 5

int main(){
    int row;
    cout << "Enter The Row Count: ";
    cin >> row;
    int i = 1;
    while(i<=row){
        int j = 1;
        while(j<=i){
            cout << i << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
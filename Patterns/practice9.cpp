// Pattern-8
// 1 2 3 
// 4 5 6
// 7 8 9

#include<iostream>
using namespace std;

int main(){
    int row;
    cout << "Enter the Row Count: ";
    cin >> row;
    int i = 1;
    int n=1;
    while(i<=row){
        int j = 0;
        while(j<row){
            cout << n << " ";
            j++;
            n++;
        }
        cout << endl;
        i++;
    }
    
    return 0;
}
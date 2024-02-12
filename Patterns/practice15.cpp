#include<iostream>
using namespace std;

// Pattern-14
// 1
// 2 1
// 3 2 1

int main(){
    int row;
    cout << "Enter The Row Count: ";
    cin >> row;
    int i = 1;
    while(i<=row){
        int j=1;
        int temp = i;
        while(j<=i){
            cout << temp << " ";
            temp--;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
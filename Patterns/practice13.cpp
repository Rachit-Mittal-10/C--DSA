#include<iostream>
using namespace std;

// Pattern-12
// 1
// 2 3
// 4 5 6

int main(){
    int row;
    cout << "Enter The Row Count: ";
    cin >> row;
    int i = 1;
    int count = 1;
    while(i<=row){
        int j = 1;
        while(j<=i){
            cout << count << " ";
            count++;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
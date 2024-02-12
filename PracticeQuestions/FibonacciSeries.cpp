// Fibonacci Series

#include<iostream>
using namespace std;

int main(){
    int limit;
    cout << "Enter the Limit: ";
    cin >> limit;
    int a = 0, b = 1;
    cout << a << " " << b << " ";
    for(int i = 1; i<=limit-2 ; i++){
        int next_term = a+b;
        cout << next_term << " ";
        a = b;
        b = next_term;
    }
    return 0;
}
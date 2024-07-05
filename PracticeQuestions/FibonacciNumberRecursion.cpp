#include<bits/stdc++.h>
using namespace std;

//Nth Fibonacci Number
int Fibonacci(int& n){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    int p1 = n -1, p2 = n - 2;
    return ( Fibonacci(p1) + Fibonacci(p2) );
}


int main(){
    int n;
    cout << "Enter the N: ";
    cin >> n;
    int Fibonacci_num = Fibonacci(n);
    cout << n << "th Fibonacci Number: " << Fibonacci_num << endl;
    return 0;
}
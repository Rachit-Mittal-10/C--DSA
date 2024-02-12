#include<iostream>
using namespace std;


// nth Term Fibonacci
int fibonacci(int n){
    int a = 0, b =1,next_term;
    n = n-2;
    while(n--){
        next_term  = a+b;
        a = b;
        b = next_term;
    }
    return next_term;
}

int main(){
    int num;
    cin >> num;
    cout << fibonacci(num) << endl;
    return 0;
}
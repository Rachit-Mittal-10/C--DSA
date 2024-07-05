#include<bits/stdc++.h>
using namespace std;

int Factorial(int n){
    if(n == 0){
        return 1;
    }
    return (n * Factorial(n-1));
    
}

int main(){
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int ans = Factorial(n);
    cout << "Factorial: " << ans << endl;
    return 0;
}
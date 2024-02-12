// Program to Find nCr

#include<iostream>
using namespace std;

int factorial(int num){
    int ans = 1;
    for(int i = 2;i<=num;i++){
        ans = ans *i;
    }
    return ans;
}

int nCr_(int n,int r){
    int nCr;
    nCr = factorial(n)/((factorial(n-r))*(factorial(r)));
    return nCr;
}

int main(){
    int n,r,n_C_r;
    cout << "Enter the n: ";
    cin >> n;
    cout << "Enter The r: ";
    cin >> r;
    if(n>=r){
        n_C_r = nCr_(n,r);
        cout << "Answer: " << n_C_r << endl;
    }
    else{
        cout << "Value of r cannot be greater than Value of n." << endl;
    }
    return 0;
}
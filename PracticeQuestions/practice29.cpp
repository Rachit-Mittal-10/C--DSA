// Given an integer number n,
// return the difference between the product of its digits and the sum of its digits.
// LeetCode Question 1281
#include<iostream>
using namespace std;

int main(){
    int n, sum = 0, product = 1,term;
    cout << "Enter the Number: ";
    cin >> n;
    while(n!=0){
        term = n%10;
        sum += term;
        product *= term;
        n = n/10;
    }
    cout << (product-sum) << endl;
    return 0;
}
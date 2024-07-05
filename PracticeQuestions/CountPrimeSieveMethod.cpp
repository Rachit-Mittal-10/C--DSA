#include<bits/stdc++.h>
using namespace std;

int CountPrime(int n);

int main(){
    int n = 5000;
    cout << CountPrime(n) << endl;
    return 0;
}
// Counting Prime number using Sieve Method
int CountPrime(int n){
    int count=0;
    vector<bool> Prime(n+1,true);
    Prime[0] = Prime[1] = false;
    for(int i=2;i<n;i++){
        if(Prime[i]){
            count++;
            for(int j=2*i;j<n;j+=i){
                Prime[j] = false;
            }
        }
    }
    return count;
}
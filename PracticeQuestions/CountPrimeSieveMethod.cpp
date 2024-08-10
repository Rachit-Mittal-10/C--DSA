#include<bits/stdc++.h>
using namespace std;

int CountPrime(int n);

int main(){
    int n = 11;
    cout << CountPrime(n) << endl;
    return 0;
}
/*
Counting Prime number using Sieve Method

Algorithm
- Initialise an array, Prime with n+1 entries of true i.e index from 0 to n
- Initialise the value of 0 and 1 as False
- Run a loop from 2 to n inclusive
    - If Prime[i] is true then run another loop which marks the all the multiples of i that lie within n as False.
    This step would reduce the number of entries to be traversed.

Time Complexity Analysis
- It takes O(N) time to initialise the vector.
- Outer loop will run n time. 
- Inner loop will run logn time
- So combined complexity of two loop is nlogn
- Final TC: O(nlogn)
*/


int CountPrime(int n){
    int count=0;
    vector<bool> Prime(n+1,true);
    Prime[0] = Prime[1] = false;
    for(int i=2;i<=n;i++){
        if(Prime[i]){
            count++;
            for(int j=2*i;j<n;j+=i){
                Prime[j] = false;
            }
        }
    }
    return count;
}
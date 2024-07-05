#include<iostream>
using namespace std;

/*
Find the ways to go from 0 to Nth Stair.
*/
int countDistinctWays(int nStairs) {
    int start = 0;
    int dest = nStairs;
    int gap = dest-start;
    if(gap == 0) return 0;
    if(gap == 1) return 1;
    if(gap == 2) return 2;
    return (countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2));
}

int main(){
   int n;
   cin >> n;
   cout << countDistinctWays(n) << endl;
   return 0;
}
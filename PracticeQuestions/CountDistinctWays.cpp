#include<iostream>
#include<unordered_map>
#include<chrono>
using namespace std;

/*
Find the ways to go from 0 to Nth Stair.
*/

int countDistinctWays(int nStairs, int& count) {
    count++;
    int start = 0;
    int dest = nStairs;
    int gap = dest-start;
    if(gap == 0) return 0;
    if(gap == 1) return 1;
    if(gap == 2) return 2;
    return countDistinctWays(nStairs - 1, count) + countDistinctWays(nStairs - 2,count);
}

// This uses DP. Greatly reducecd time and amount of function calls
int countDistinctWays(int nStairs, unordered_map<int,int>& memory, int& count){
    count++;
    int start = 0;
    int dest = nStairs;
    int gap = dest - start;
    if(gap == 0) return 0;
    if(gap == 1) return 1;
    if(gap == 2) return 2;
    if(memory.find(gap) != memory.end()){
        return memory[gap];
    }
    int ans1 = countDistinctWays(nStairs-1,memory, count);
    memory[nStairs-1] = ans1;
    int ans2 = countDistinctWays(nStairs-2,memory, count);
    memory[nStairs-2] = ans2;
    return ans1+ans2;
}

int countDistinctWayWrapper(int nStairs, int& count){
    unordered_map<int,int> memory;
    return countDistinctWays(nStairs, memory, count);
}

int main(){
   int count1, count2;
   int n;
   cin >> n;
   auto start1 = chrono::high_resolution_clock::now();
   count1 = 0;
   countDistinctWays(n, count1);
   auto end1 = chrono::high_resolution_clock::now();
   auto start2 = chrono::high_resolution_clock::now();
   count2 = 0;
   countDistinctWayWrapper(n, count2);
   auto end2 = chrono::high_resolution_clock::now();
   chrono::duration<double> d1 = end1 - start1;
   chrono::duration<double> d2 = end2 - start2;
   cout << d1.count() << " | " << count1 << endl << d2.count() << " | " << count2 << endl;
   return 0;
}
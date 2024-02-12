#include<bits/stdc++.h>
using namespace std;
/*
Time Complexity: O(N)
Space Complexity: O(N)

Reduced Function Calls
*/
int fibonacci(int n, vector<int>& memory){
    if(n <= 1){
        memory[n] = n;
        return n;
    }
    int n1, n2;
    if(memory[n-1] != -1){
        n1 = memory[n-1];
    }else{
        n1 = fibonacci(n-1,memory);
    }
    if(memory[n-2] != -1){
        n2 = memory[n-2];
    }else{
        n2 = fibonacci(n-2,memory);
    }
    int fib = n1 + n2;
    memory[n] = fib;
    return fib;
}

int Fibonacci(int n){
    if(n<=1){
        return n;
    }
    return Fibonacci(n-2) + Fibonacci(n-1);
}

int main(){
    int n = 60;
    vector<int> memory(n+1,-1);
    chrono::high_resolution_clock::time_point start, end;
    chrono::duration<double> duration;
    start = chrono::high_resolution_clock::now();
    int ansMemory = fibonacci(n,memory);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << duration.count() << endl;
    start = chrono::high_resolution_clock::now();
    int ansRecur = Fibonacci(n);
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << duration.count() << endl;
    return 0;
}
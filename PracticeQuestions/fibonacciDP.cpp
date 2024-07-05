#include<iostream>
#include<vector>
using namespace std;
/*
Time Complexity: O(N)
Space Complexity: O(N)

Reduced Function Calls
*/

// Recursive Function with Memorization
// Maximum Value of N: 4950
int fibonacci(int n, vector<int>& memory){
    // Base Case
    if(n <= 1){
        memory[n] = n;
        return n;
    }
    // We check if we have value stored
    // if not then value calculated
    if (memory[n] != -1) {
        return memory[n];
    }
    int fib = fibonacci(n-1,memory) + fibonacci(n-2,memory);
    memory[n] = fib;
    return fib;
}

// Recursive Function
int Fibonacci(int n){
    if(n<=1){
        return n;
    }
    return Fibonacci(n-2) + Fibonacci(n-1);
}

int main(){
    int n;
    cout << "Enter the n: ";
    cin >> n;
    vector<int> memory(n+1,-1);
    cout << "fibonacci of " << n <<  ": " << fibonacci(n, memory) << endl;
    return 0;
}
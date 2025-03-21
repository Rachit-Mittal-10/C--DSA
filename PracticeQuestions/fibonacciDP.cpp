#include <iostream>
#include <vector>
using namespace std;
/*
Time Complexity: O(N)
Space Complexity: O(N)

Reduced Function Calls
*/

/*
 * Recursive Function with Memorization
 * Maximum Value of N: 4950
 */
int fibonacci(int n, vector<int> &memory)
{
    // Base Case
    if (n <= 1)
    {
        memory[n] = n;
        return n;
    }
    // We check if we have value stored
    // if not then value calculated
    if (memory[n] != -1)
    {
        return memory[n];
    }
    int fib = fibonacci(n - 1, memory) + fibonacci(n - 2, memory);
    memory[n] = fib;
    return fib;
}

/*
 * Tabulation
 * No Recursion
 * Only Loops
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */
int Fibonacci(int n)
{
    vector<int> table(n + 1, -1);
    table[0] = 0;
    table[1] = 1;
    if (n < 0)
    {
        return -1;
    }
    if (n <= 1)
    {
        return table[n];
    }
    for (int i = 2; i <= n; i++)
    {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n];
}

/*
 * Space Optimised Fibonacci Code
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
int fibonacciSpace(int n)
{
    if (n < 0)
    {
        return -1;
    }
    if (n <= 1)
    {
        return n;
    }
    int prev2 = 0;
    int prev = 1;
    int curr;
    for (int i = 2; i <= n; i++)
    {
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}

int main()
{
    int n;
    cout << "Enter the n: ";
    cin >> n;
    vector<int> memory(n + 1, -1);
    cout << "Memorization" << endl;
    cout << "fibonacci of " << n << ": " << fibonacci(n, memory) << endl;
    cout << endl;
    cout << "Tabulation" << endl;
    cout << "fibonacci of " << n << ": " << Fibonacci(n) << endl;
    cout << endl;
    cout << "Space Optimised" << endl;
    cout << "fibonacci of " << n << ": " << fibonacciSpace(n) << endl;
    return 0;
}
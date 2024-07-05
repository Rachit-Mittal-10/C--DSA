#include<bits/stdc++.h>
using namespace std;

/*
Question Link: https://www.codingninjas.com/studio/problems/n-stacks-in-an-array_1164271?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&campaign=Lovebabbarcodestudio11thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio11thfeb
Approach 1: 
Allocate a fixed space to each stack
Not a efficient way for memory management

Approach 2: 
Maintain a top, next array.
Top will contain index of top element
Next will either represent empty space or next top element of stack


Solution Link: https://www.youtube.com/watch?v=lrSXKLmnMV8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=63&t=166s&ab_channel=CodeHelp-byBabbar
*/

class NStack
{
    int freespot,n,s;
    int *array,*top,*next;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        array = new int[S];
        freespot = 0;
        n = N;
        s = S;
        top = new int[N];
        for(int i=0;i<N;i++){
            top[i] = -1;
        }
        next = new int[S];
        for(int i=0;i<S;i++){
            next[i] = i+1;
        }
        next[S-1] = -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        // Check for Overflow
        if(freespot == -1){
            return false;
        }
        
        // If No Overflow then Insertion
        
        // Step 1: Find Index
        int index = freespot;
        // Step 2: Update Freespot
        freespot = next[index];
        // Insert into Array
        array[index] = x;
        // Update Next
        next[index] = top[m-1];
        // Update Top
        top[m-1] = index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        // For Pop Reverse the Order of Push
        if(top[m-1] == -1){
            return -1;
        }
        
        int index = top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freespot;
        
        freespot = index;
        return array[index];
    }
};

int main(){
  NStack N1(3,6);
  N1.pop(2);
  N1.push(8,2);
  N1.push(1,2);
  N1.push(25,2);
  N1.push(41,3);
  N1.push(20,2);
  N1.push(17,2);
  N1.pop(2);
  N1.pop(2);
  N1.pop(2);
  return 0;
}
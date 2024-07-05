/*
This program deletes the middle element of stack.
*/

#include <bits/stdc++.h> 
using namespace std;
void solve(stack<int>&inputStack, int count,int size){
   if(count == size/2){
      inputStack.pop();
      return;
   }
   int element = inputStack.top();
   inputStack.pop();
   count++;
   solve(inputStack,count,size);
   inputStack.push(element);
   return;
}

void deleteMiddle(stack<int>&inputStack, int N){
   int count = 0;
   solve(inputStack,0,N+1);
}

int main(void){
    stack<int> inputStack;
    inputStack.push(1);
    inputStack.push(2);
    inputStack.push(3);
    inputStack.push(4);

    deleteMiddle(inputStack,3);
}


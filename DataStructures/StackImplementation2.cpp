#include<bits/stdc++.h>
using namespace std;
// Array Implementaion
class Stack{
    int A[10];
    int top;
    public:
        Stack(){
            top = -1;
        }
        void Push(int x){
            if(top == 9){
                cout << "Stack Overflow" << endl;
                return;
            }
            top++;
            A[top] = x;
        }
        void Pop(){
            if(top == -1){
                cout << "Stack Underflow" << endl;
                return;
            }
            top--;
        }
        void Display(){
            if(top == -1){
                cout << "Stack Underflow" << endl;
                return;
            }
            for(int i = 0; i <= top ; i++){
                cout << A[i] << " ";
            }cout << endl;
        }
        void Peek(){
            if(top == -1){
                cout << "Stack Underflow" << endl;
                return;
            }
            cout << A[top] << endl;
        }
        void GetTop(){
            cout << top << endl;
        }
};

int main(){
    Stack S;
    S.Display();    // outputs the Stack Underflow
    S.Push(1);
    S.Push(0);
    S.Push(2);
    S.Display();    // outputs the 1 0 2
    S.Pop();
    S.Display();    // outputs the 1 0
    S.GetTop();     // outputs the '1' which is top value currently
    S.Peek();       // outputs the 0 which A[top = 1]
    return 0;
}
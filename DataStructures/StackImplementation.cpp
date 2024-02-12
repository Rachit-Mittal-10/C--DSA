#include<bits/stdc++.h>
using namespace std;

int Stack[100];
int top = -1;
int __size___ = 100;

void Push(int element){
    if(top >= _size__-1){
        cout << "Stack Overflow" << endl;
    }else{
        top++;
        Stack[top] = element;
    }
}

void Pop(){
    if(top<=-1){
        cout << "Stack Underflow" << endl;
    }
    else{
        cout << "Popped Element: " << Stack[top] << endl;
        top--;
    }
}

void Peek(){
    if(top<=-1){
        cout << "Stack is Empty";
    }else{
        cout << "Peeked Element at Top: " << Stack[top] << endl;
    }
}

void Display(){
    if(top<=-1){
        cout << "Empty Stack" << endl;
    }else{
        for(int i=top;i>=0;i--){
            cout << Stack[i] << " ";
        }
        cout << endl;
    }
}

// Stack Implementation
int main(){
    int element,choice;
    cout << "::::Stack Implementation::::" << endl;
    cout << "1) Push\n2) Pop\n3) Peek\n4) Display\n5) Exit" << endl;
    do{
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the Element: ";
            cin >> element;
            Push(element);
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peek();
            break;
        case 4:
            Display();
            break;
        case 5:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }while(choice!=5);
    return 0;
}
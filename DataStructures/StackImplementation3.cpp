#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node(){
            data = 0;
            next = NULL;
        }
        Node(int input){
            data = input;
            next = NULL;
        }
};
/*
Linked List Based Implementation
We will push/insert and pop/delete from head/top end of the Linked List.
Since Stack is supposed to do push and pop in O(1) time complexity.
Push and Pop from end is not possible.
*/
class Stack:public Node{
    Node *top;
    public:
        Stack(){
            top = NULL;
        }
        void Push(int input){
            Node *NewNode = new Node(input);
            NewNode->next = top;
            top = NewNode;
        }
        void Pop(){
            if(top == NULL){
                cout << "Stack Underflow" << endl;
                return;
            }
            Node *temp = top;
            top = top->next;
            delete temp;
        }
        void Display(){
            if(top == NULL){
                cout << "Empty Stack" << endl;
                return;
            }
            Node *temp = top;
            while(temp){
                cout << temp->data << " ";
                temp = temp->next;
                
            }cout << endl;
        }
        void GetTop(){
            if(top == NULL){
                cout << "Empty Stack" << endl;
                return;
            }
            cout << top->data << endl;
        }
};


int main(){
    Stack S;
    cout << boolalpha << S.IsEmpty() << endl;   // outputs true
    S.Display();    // outputs the Empty Stack
    for(int i = 1; i<6;i++){
        S.Push(i);
    }
    S.Display();    // outputs the 5 4 3 2 1
    S.Pop();
    S.Display();    // outputs the 4 3 2 1
    S.GetTop();     // outputs the 4
    cout << boolalpha << S.IsEmpty() << endl;   // outputs false
    return 0;
}
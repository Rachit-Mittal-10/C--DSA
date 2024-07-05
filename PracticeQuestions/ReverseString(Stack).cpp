#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char character;
    Node *next;
    Node(){
        next = NULL;
    }
    Node(char input){
        character = input;
        next = NULL;
    }
};

class Stack{
    Node *top;
    public:
    Stack(){
        top = NULL;
    }
    void Push(char input){
        Node *NewNode = new Node(input);
        NewNode->next = top;
        top = NewNode;
    }
    char Pop(){
        Node *temp = top;
        top = top->next;
        char returnee = temp->character;
        delete temp;
        return returnee;
    }
};

// Reversal of String using stack
// Time Complexity: O(N)
// Space Complexity: O(N)
int main(){
    string name;
    cout << "Enter the String: ";
    getline(cin,name);
    Stack S;
    int length = name.size();
    for(char c:name){
        S.Push(c);
    }
    for(int i=0;i<length;i++){
        name[i] = S.Pop();
    }
    cout << "Reversed String is: " << name << endl;

    return 0;
}
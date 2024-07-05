#include<bits/stdc++.h>
using namespace std;
/*
In this question, We need to make the last node to first Node
Input LL : 1->2->3

Output LL : 3->1->2 
*/
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* LastToFirst(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* lastNode = head;
    Node* secondLast = NULL;
    while(lastNode->next!=NULL){
        secondLast = lastNode;
        lastNode = lastNode->next;
    }
    lastNode->next = head;
    secondLast->next = NULL;
    head = lastNode;
    return head;
}

void Print(Node* head){
    
    while(head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }cout << endl;
    return;
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(4);
    n1->next = n2;
    n2->next = n3;
    Node* h1 = n1;
    cout << "Linked List before Function Call" << endl;
    Print(h1);
    cout << endl;
    h1 = LastToFirst(h1);
    cout << "Linked List after Function Call" << endl;
    Print(h1);
    return 0;
}
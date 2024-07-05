#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

bool isCircular(Node* head){
    if(head == NULL){
        return true;
    }
    Node* temp = head->next;
    while(temp != head && temp!= NULL){
        temp = temp->next;
    }
    if(temp == NULL){
        return false;
    }
    if(temp == head){
        return true;
    }
    return false;
}

int main(){
    Node* head;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    node1->next = node2;
    node2->next = node3;

    head = node1;
    cout << boolalpha << isCircular(head) << endl;
    return 0;
}
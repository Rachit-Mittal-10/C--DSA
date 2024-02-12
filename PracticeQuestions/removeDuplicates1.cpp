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

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

void removeDuplicates(Node** head_ptr){
    Node* curr = *head_ptr;
    Node* deletee;
    while(curr!=NULL){
        if(curr->data == (curr->next)->data){
            deletee = curr->next;
            curr->next = curr->next->next;
            delete deletee;
        }
        curr = curr->next;
    }
}

int main(){
    Node *node1, *node2, *node3, *node4, *node5, *node6;

    node6 = new Node(4);
    node5 = new Node(3,node6);
    node4 = new Node(3,node5);
    node3 = new Node(2,node4);
    node2 = new Node(2,node3);
    node1 = new Node(1,node2);

    Node* head = node1;

    removeDuplicates(&head);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;
    Node(){
        this->prev = NULL;
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }

    Node(int data, Node* next, Node* prev){
        this->prev = prev;
        this->data = data;
        this->next = next;
    }
};

Node* removeDuplicates(Node* head){
    Node* curr = head->next;
    Node* deletee;
    while(curr->next!=NULL){
        if(curr->data == (curr->prev)->data){
            deletee = curr;
            (curr->prev)->next = curr->next;
            (curr->next)->prev = curr->prev;
            curr = curr->next;
            delete deletee;
        }
        else if(curr->data == (curr->next)->data){
            deletee = curr;
            (curr->prev)->next = curr->next;
            (curr->next)->prev = curr->prev;
            curr = curr->next;
            delete deletee;
        }
        else{
          curr = curr->next;
        }
    }
    return head;
}

int main(){
    Node *node1, *node2, *node3, *node4, *node5;

    node1 = new Node(1);
    node2 = new Node(1);
    node3 = new Node(2);
    node4 = new Node(2);
    node5 = new Node(3);

    node1->prev = NULL;
    node1->next = node2;

    node2->prev = node1;
    node2->next = node3;

    node3->prev = node2;
    node3->next = node4;

    node4->prev = node3;
    node4->next = node5;

    node5->prev = node4;
    node5->next = NULL;

    Node* head = node1;

    head = removeDuplicates(head);
    return 0;
}
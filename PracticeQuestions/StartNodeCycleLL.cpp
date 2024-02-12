/*
This is the extension of Floyd Cycle Detection Algorithm
*/

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


/*
Intersection Node in Floyd Cycle Detection Algorithm will have distance from beginning node anticlockwise equal to distance of head node from beginning node.
Limitation: Circular Linked List. In Circular Linked List, Code fails due to being extension of Floyd Cycle Detectiomn Algorithm.
*/
Node* StartNodeofCycle(Node* head){
    Node *slow, *fast;
    slow = fast = head;

    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            break;
        }
    }

    while(slow!=NULL && fast!=NULL){
        slow = slow->next;
        fast = fast->next;

        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

int main(){
    Node* head;
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node2;
    // CLL:: 1 2 3 4 5 2
    head = node1;

    cout << StartNodeofCycle(head)->data << endl;
    return 0;
}
/*
Floyd's Cycle Detection Algorithm
This Algorithm uses two pointer approach where fast pointer moves twice as fast as slow pointer.
If they meet then loop exist otherwise no.
Link: https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/

Time Complexity: O(n)
Space Complexity: O(1)
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

bool FloydAlgo(Node* head){
    if(head == NULL){
        return false;
    }
    Node *slow,*fast;
    slow = fast = head; 
    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
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

    cout << boolalpha << FloydAlgo(head) << endl;
    return 0;
}
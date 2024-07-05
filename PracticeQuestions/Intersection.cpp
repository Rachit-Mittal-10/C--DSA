/*
Question Link: https://leetcode.com/problems/intersection-of-two-linked-lists/solutions/

# Brute Force Approach:
Two While Loops

# Optimised Approach: Two Pointer Approach
We traverse through both the heads given while two pointers are not equal.
If they are not equal and one of two is equal to null, We re-initialise the pointer with other head given.
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
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
    Node(int val, Node* address){
        this->data = val;
        this->next = address;
    }
};
Node* getIntersectionNode(Node *headA, Node *headB) {
        
    if(headA == NULL || headB == NULL){
        return NULL;
    }

    Node* temp1 = headA;
    Node* temp2 =  headB;

    while(temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == NULL){
            temp1 = headB;
        }
        if(temp2 == NULL){
            temp2 = headA;
        }
    }
    return temp1;
}
int main(){
    Node* n1 = new Node(2);
    Node* n2 = new Node(3);
    n1->next = n2;
    Node* head1 = n1;
    Node* head2 = n2;

    Node* ans = getIntersectionNode(head1,head2);
    cout << ans << endl;
    return 0;
}
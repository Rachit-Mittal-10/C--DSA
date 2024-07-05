/*
Question Link:: https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
Node *Merge(Node *first, Node *second)
{
    Node *head = new Node(-1);
    Node *temp = head;
    while (first != NULL && second != NULL)
    {
        if (first->data <= second->data)
        {
            temp->next = first;
            first = first->next;
        }
        else
        {
            temp->next = second;
            second = second->next;
        }
        temp = temp->next;
    }
    if (first != NULL)
    {
        temp->next = first;
    }
    if (second != NULL)
    {
        temp->next = second;
    }
    temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    return head;
}
// Function to merge K sorted linked list.
Node *mergeKLists(Node *arr[], int K)
{
    // Your code here
    int i = 0;
    while (i < K - 1)
    {
        arr[i + 1] = Merge(arr[i], arr[i + 1]);
        i++;
    }
    return arr[i];
}

int main(void){
    Node* a1 = new Node(1);
    Node* a2 = new Node(2);
    Node* a3 = new Node(3);
    a1->next = a2;
    a2->next = a3;

    Node* b1 = new Node(4);
    Node* b2 = new Node(5);
    b1->next = b2;

    Node* c1 = new Node(6);
    Node* c2 = new Node(7);
    c1->next = c2;

    Node* d1 = new Node(8);
    Node* h1 = a1;
    Node* h2 = b1;
    Node* h3 = c1;
    Node* h4 = d1;
    Node* h5;
    Node *arr[4];
    arr[0] = h1;
    arr[1] = h2;
    arr[2] = h3;
    arr[3] = h4;

    h5 = mergeKLists(arr,4); 
    return 0;
}
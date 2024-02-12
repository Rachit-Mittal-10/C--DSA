/*
Question Link: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

We need to add two numbers represented by Linked List.
Approach:
Step-1: Reverse
Step-2: Add
Step-3: Reverse
Step4: Return

Time Complexity: O(max(M,N));
M,N: length of LLs

Space Complexity: O(1)
A slight memory will be taken by Memory Stack but it would be constant hence O(1).
*/


#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int GetLength(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}
Node *Reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node *Add(Node *first, Node *second)
{
    // Here We assume length of first LL is always greater than second
    Node *t1 = first;
    Node *t2 = second;
    int sum = 0;
    int carry = 0;
    int digit = 0;
    Node* t1_p = NULL;
    while (t1 != NULL && t2 != NULL)
    {
        sum = t1->data + t2->data + carry;
        carry = sum / 10;
        digit = sum % 10;
        t1->data = digit;
        t1_p = t1;
        t1 = t1->next;
        t2 = t2->next;
    }
    while(t1!=NULL && carry!=0){
        sum = t1->data + carry;
        carry = sum / 10;
        digit = sum % 10;
        t1->data = digit;
        t1_p = t1;
        t1 = t1->next;
    }
    if(carry!=0){
        Node* added = new Node(carry);
        t1_p->next = added;
    }
    return first;
}

// Function to add two numbers represented by linked list.
Node *addTwoLists(Node *first, Node *second)
{
    first = Reverse(first);
    second = Reverse(second);
    int first_len = GetLength(first);
    int second_len = GetLength(second);

    if (first_len >= second_len)
    {
        first = Add(first, second);
    }
    else
    {
        first = Add(second, first);
    }
    first = Reverse(first);
    return first;
}

int main()
{
    Node *h1,*h2;
    //555
    Node* a1 = new Node(5);
    Node* a2 = new Node(5);
    Node* a3 = new Node(5);


    a1->next = a2;
    a2->next = a3;


    //555
    Node* b1 = new Node(5);
    Node* b2 = new Node(5);
    Node* b3 = new Node(5);

    b1->next = b2;
    b2->next = b3;


    h1 = a1;
    h2 = b1;

    Node* h3 = addTwoLists(h1,h2);
    return 0;
}
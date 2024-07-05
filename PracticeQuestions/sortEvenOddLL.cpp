/*
Question Link:: https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *divide(int N, Node *head)
{
    Node *head_even = new Node(-2);
    Node *tail_even = head_even;
    Node *head_odd = new Node(-1);
    Node *tail_odd = head_odd;
    Node *even = head_even;
    Node *odd = head_odd;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            even->next = temp;
            even = even->next;
            tail_even = even;
        }
        else
        {
            odd->next = temp;
            odd = odd->next;
            tail_odd = odd;
        }
        temp = temp->next;
    }
    tail_odd->next = NULL;
    tail_even->next = head_odd->next;

    head = head_even->next;
    return head;
}

int main()
{
    Node *n1 = new Node(17);
    Node *n2 = new Node(15);
    Node *n3 = new Node(8);
    Node *n4 = new Node(9);
    Node *n5 = new Node(2);
    Node *n6 = new Node(4);
    Node *n7 = new Node(6);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    Node *h1 = n1;

    h1 = divide(h1);
    return 0;
}
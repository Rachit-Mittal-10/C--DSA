/*
Merge Sort in linked list by changing the links opposed to changing data in nodes.
*/

class node
{
public:
  int data;
  node *next;
  node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

#include <bits/stdc++.h>
using namespace std;

node *GetMid(node *head)
{
  node *slow = head;
  node *fast = head;
  node *mid;
  while (slow != NULL && fast != NULL && fast->next != NULL)
  {
    mid = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  return mid;
}

node *Merge(node *head1, node *head2)
{
  node *t1 = head1;
  node *t2 = head2;
  node *headSorted = NULL;
  node *t3 = NULL;
  if (t1->data <= t2->data)
  {
    headSorted = t1;
    t1 = t1->next;
  }
  else
  {
    headSorted = t2;
    t2 = t2->next;
  }
  t3 = headSorted;
  while (t1 != NULL && t2 != NULL)
  {
    if (t1->data <= t2->data)
    {
      t3->next = t1;
      t1 = t1->next;
    }
    else
    {
      t3->next = t2;
      t2 = t2->next;
    }
    t3 = t3->next;
  }
  if (t1 != NULL)
  {
    t3->next = t1;
  }
  if (t2 != NULL)
  {
    t3->next = t2;
  }
  return headSorted;
}

node *mergeSort(node *head)
{
  // Base Case
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  node *mid = GetMid(head);
  node *left = head;
  node *right = mid->next;
  mid->next = NULL;
  left = mergeSort(left);
  right = mergeSort(right);
  head = Merge(left, right);
  return head;
}

int main()
{
  node *n1 = new node(5);
  node *n2 = new node(-2);
  node *n3 = new node(10);
  node *n4 = new node(4);
  node *n5 = new node(8);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  node *h1 = n1;
  h1 = mergeSort(h1);
  return 0;
}
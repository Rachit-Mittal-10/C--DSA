/*
Question Link: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
Check whether the given Linked List is Palindrome or not.

Approach1: 
Find the Middle Node. Reverse the LL after Middle Node.
Compare the two halves of LL.(Part till Middle Node and Part after Middle Node)

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

// This function reverses the LL.
Node* Reverse(Node* head){
  Node* curr = head;
  Node* prev = NULL;
  Node* next;
  
  while(curr!=NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

// This function returns the middle node of LL.
Node* middle_node(Node* head){
  int len = 0;
  int mid;
  Node* temp = head;
  while(temp!=NULL){
    len++;
    temp = temp->next;
  }
  
  mid = len/2;
  if(len%2 != 0){
    mid = mid + 1;
  }
  temp = head;
  while(--mid){
    temp = temp->next;    
  }
  return temp;
}

// Actual Function to check Palindrome
bool isPalindrome(Node *head){
  if(head == NULL || head->next == NULL){
    return true;
  }
  
  Node* middle = middle_node(head);
  Node* temp = middle->next;
  
  middle->next = Reverse(temp);
  
  temp = middle->next;
  
  Node* temp2 = head;

  while((temp!= NULL) && (temp2!=NULL)){
    if(temp->data != temp2->data){
      return false;
    }
    temp = temp->next;
    temp2 = temp2->next;
  }
  return true;
}

int main(void){
  Node* h1;
  Node* n1 = new Node(1);
  Node* n2 = new Node(2);
  Node* n3 = new Node(2);
  Node* n4 = new Node(1);
  h1 = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  cout << boolalpha << isPalindrome(h1) << endl;
  return 0;
}
#include<bits/stdc++.h>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class compare{
public:
    bool operator()(Node* a, Node* b){
        return (a->data > b->data);
    }
};

Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    Node* head = new Node(-1);
    Node* tail = head;

    for(auto i: listArray){
        minHeap.push(i);
    }

    while(!minHeap.empty()){
        Node* t = minHeap.top();
        minHeap.pop();
        tail->next = t;
        tail = tail->next;
        if(t->next != NULL)
            minHeap.push(t->next);
    }

    Node* d = head;
    head = head->next;
    delete d;
    return head;
}


int main(){
    Node *a1, *a2, *a3,*a4;
    Node *b1, *b2,*b3;
    Node *c1, *c2;
    a4 = new Node(8);
    a3 = new Node(6,a4);
    a2 = new Node(4,a3);
    a1 = new Node(2,a2);

    b3 = new Node(7);
    b2 = new Node(5,b3);
    b1 = new Node(3,b2);

    c2 = new Node(11);
    c1 = new Node(10,c2);

    vector<Node*> array;
    array.push_back(a1);
    array.push_back(b1);
    array.push_back(c1);

    Node* r1 = mergeKLists(array);
    return 0;
}
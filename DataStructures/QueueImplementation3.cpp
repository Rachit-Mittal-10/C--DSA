#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(){
            data = 0;
            next = NULL;
        }
        Node(int input){
            data = input;
            next = NULL;
        }
};

class _Queue_{
    // Linked List Implementation
    // Deletion at Front
    // Insertion at Rear
   Node *front;
   Node *rear;
    public:
        _Queue_(){
            front = NULL;
            rear = NULL;
        }

        void enqueue(int input){
            Node *NewNode = new Node(input);
            if(front == NULL && rear == NULL){
                front = NewNode;
                rear = NewNode;
                return;
            }
            rear->next = NewNode;
            rear = NewNode;            
        }

        void dequeue(){
            Node *temp = front;
            if(front == NULL){
                cout << "Empty Queue" << endl;
                return;
            }
            if(front == rear){
                rear = NULL;
            }
            front = front->next;
            delete temp;
        }

        void Print(){
            Node *temp = front;
            while(temp){
                cout << temp->data << " ";
                temp = temp->next;
            }cout <<endl;
        }
};



int main(){
    _Queue_ Q;
    Q.dequeue();    // Outputs Empty Queue
    Q.enqueue(5);
    Q.enqueue(4);
    Q.enqueue(3);
    Q.enqueue(2);
    Q.enqueue(1);
    Q.Print();  // outputs 5 4 3 2 1
    Q.dequeue();
    Q.Print();  // outputs 4 3 2 1
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(){
            data = 0;
            next = NULL;
            prev  = NULL;
        }
        Node(int input){
            data = input;
            next = NULL;
            prev  = NULL;
        }
};

class Doubly_Linked_List : public Node{
    Node *head;
    Node *tail;
    public:
        Doubly_Linked_List(){
            head = NULL;
            tail = NULL;
        }
        void ForwardPrint(){
            // head to tail
            if(head == NULL){
                cout << "Empty Doubly Linked List" << endl;
                return;
            }
            Node*temp = head;
            while(temp){
                cout << temp->data << " ";
                temp = temp->next;
            }cout << endl;
        }
        void ReversePrint(){
            // tail to head
            if(tail == NULL){
                cout << "Empty Linked List" << endl;
                return;
            }
            Node *temp = tail;
            while(temp){
                cout << temp->data << " ";
                temp = temp->prev;
            }cout << endl;
        }
        void InsertAtHead(int input){
            Node *NewNode = new Node(input);
            if(head == NULL){
                head = NewNode;
                tail = NewNode;
                return;
            }
            NewNode->next = head;
            head->prev = NewNode;
            head = NewNode;
        }
        void InsertAtTail(int input){
            Node *NewNode = new Node(input);
            if(tail == NULL){
                head = NewNode;
                tail = NewNode;
                return;
            }
            NewNode->prev = tail;
            tail->next = NewNode;
            tail = NewNode;
        }
        void DeleteAtHead(){
            Node *temp =head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
        void DeleteAtTail(){
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
};

int main(){
    Doubly_Linked_List L1;
    L1.InsertAtHead(1);
    L1.InsertAtTail(2);
    L1.InsertAtTail(3);
    L1.InsertAtHead(-1);
    L1.ForwardPrint();  // outputs the -1 1 2 3
    L1.ReversePrint();  // outputs the 3 2 1 -1
    L1.DeleteAtHead();
    L1.DeleteAtTail();
    L1.ForwardPrint();  // 1 2
    return 0;
}
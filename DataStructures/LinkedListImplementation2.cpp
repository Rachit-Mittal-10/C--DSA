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

class Linked_List : public Node{
    Node *head;
    int len;
    public:
        Linked_List(){
            head = NULL;
            len = 0;
        }
        void Insert(int input){
            Node *NewNode = new Node(input);
            if(head == NULL){
                head = NewNode;
                len++;
                return;
            }
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = NewNode;
            len++;
        }
        Node* GetHead(){
            return head;
        }
        void Print(Node *t){
            if(t == NULL){
                return;
            }
            // For Forward order printing of the elements, Recursive Call after Cout Statement
            cout << t->data << " ";
            Print(t->next);           
        }
        void Reverse_Print(Node *t){
            // For Reverse Order printing of the elements, Recursive Call before Cout Statement
            if(t == NULL){
                return;
            }
            Reverse_Print(t->next);
            cout << t->data << " ";
        }
};

int main(){
    Linked_List L1;
    L1.Insert(1);
    L1.Insert(2);
    L1.Insert(3);
    L1.Insert(4);
    L1.Insert(5);
    L1.Insert(6);
    L1.Print(L1.GetHead());
    cout << endl;
    L1.Reverse_Print(L1.GetHead());
    return 0;
}
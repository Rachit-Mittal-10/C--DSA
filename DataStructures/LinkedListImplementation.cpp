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
        void Insert(int input, int position){
            Node *NewNode = new Node(input);
            if(position == len){
                Insert(input);
                len++;
                return;
            }
            if(position == 1){
                NewNode->next = head;
                head = NewNode;
                len++;
                return;
            }
            if(position > len || position < 1){
                cout << "Wrong Position" << endl;
                return;
            }

            Node *temp = head;
            int i = 1;
            while(i++ < (position-1)){
                temp = temp->next;
            }
            NewNode->next = (temp->next);
            temp->next = NewNode;
            len++;
        }
        void Print(){
            Node *temp = head;
            if(head == NULL){
                cout << "Empty  Linked List" << endl;
                return;
            }
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }cout << endl;
        }
        void Delete(int position){
            if(position < 1 || position > len){
                cout << "Wrong Position" << endl;
                return;
            }
            if(position == 1){
                Node *temp1 = head;
                head = head->next;
                delete temp1;
                return;
            }
            Node *temp = head;
            int i = 1;
            while(i++ < (position-1)){
                temp = temp->next;
            }
            Node *deleted = temp->next;
            temp->next = (temp->next)->next;
            delete deleted;
        }
        void Reverse(){
            // Iterative Approach
            // Three Pointer Approach for Reversal
            Node *next, *prev, *current;
            current = head;
            prev = NULL;
            while(current != NULL){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
        void Reverse_2(Node *p){
            // Recursive Approach
            // Implicit Stack due to the fact, the function calling uses stack for function call management
            if(p->next == NULL){    // Exit Condition for Recursion
                head = p;
                return;
            }
            Reverse_2(p->next);   // Recursive Call
            // Node Fix
            Node* q = p->next;
            q->next = p;
            p->next = NULL;
        }
        void Reverse_3(){
            // Reversal using stack
            // Explicit Stack since we are using the Stack data structures in the code explicitly
            stack<Node*> S;
            Node *temp = head;
            while(temp){
                S.push(temp);
                temp = temp->next;
            }
            Node *temp2 = S.top();
            head = temp2;
            S.pop();
            while(!S.empty()){
                temp2->next = S.top();
                S.pop();
                temp2 = temp2->next;
            }
            temp2->next = NULL;
        }
        Node* GetHead(){
            return head;
        }
        int GetLength(){
            return len;
        }
};

int main(){
    Linked_List L1;
    L1.Print(); // output 'Empty linked list'
    L1.Insert(1);
    L1.Insert(2);
    L1.Insert(3);
    // L1.Insert(4);
    L1.Insert(5);
    L1.Insert(6);
    L1.Print(); // output the Linked list at this stage : 1 2 3 5 6
    L1.Insert(4,4);
    L1.Print(); // 1 2 3 4 5 6 
    L1.Insert(4,9); // outputs Wrong Position
    cout << L1.GetLength() << endl; // outputs length of linked list which is 6 currently
    L1.Delete(1);
    L1.Print(); // 2 3 4 5 6
    L1.Delete(4);
    L1.Print(); // 2 3 4 6
    L1.Delete(0);   // outputs Wrong Position
    L1.Reverse();   // Reverses the Linked List(Iterative Way)
    L1.Reverse_2(L1.GetHead()); // Reverses the Linked List(Recursive Way)
    L1.Print(); // Outputs the 6 4 3 2
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(){
            this->data = 0;
            this->next = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        ~Node(){
            this->next = NULL;
        }
};

class CircularLinkedList{
    Node* tail;
    int len;
    public:
        CircularLinkedList(){
            this->tail = NULL;
            this->len = 0;
        }

        bool CheckEmpty(){
            if(tail == NULL){
                return true;
            }
            return false;
        }

        void InsertAtTail(int data){
            Node* NewNode = new Node(data);
            len++;
            if(CheckEmpty()){
                tail = NewNode;
                return;
            }
            if(this->tail->next == NULL){
                NewNode->next = tail;
            }else{
                NewNode->next = tail->next;
            }
            tail->next = NewNode;
            tail = NewNode;
            return;
        }

        void InsertAtData(int data_inserted, int data_after){
            Node* NewNode = new Node(data_inserted);
            if(CheckEmpty()){
                cout << "Insertion not possible\nEmpty Circular Linked List" << endl;
                return;
            }
            Node* temp = tail;
            int count = 0;
            while(temp->data != data_after){
                temp = temp->next;
                count ++;
                if(count >= len){
                    cout << "Data not found" << endl;
                    return;
                }
            }
            len++;
            NewNode->next = temp->next;
            temp->next = NewNode;
            return;
        }

        void InsertAtHead(int data){
            Node* NewNode = new Node(data);
            len++;
            if(CheckEmpty()){
                tail = NewNode;
                return;
            }
            if(this->tail->next == NULL){
                NewNode->next = tail;
            }else{
                NewNode->next = tail->next;
            }
            tail->next = NewNode;
            return;
        }

        void DeleteAtTail(){
            if(CheckEmpty()){
                cout << "Empty Linked List\nDeletion Not Possible" << endl;
                return;
            }
            len--;
            Node* temp2 = tail;
            if(this->tail->next == NULL){
                tail = NULL;
                delete temp2;
                return;
            }
            Node* temp = tail->next;
            while(temp->next!=tail){
                temp = temp->next;
            }
            temp->next = tail->next;
            tail = temp;
            delete temp2;
            return;
        }
        void DeleteAtHead(){
            if(CheckEmpty()){
                cout << "Empty Linked List\nDeletion not possible" << endl;
                return;
            }
            len--;
            Node* temp = tail->next;
            tail->next = temp->next;
            delete temp;
            return;
        }
        void Print(){
            int count = 0;
            if(this->tail == NULL){
                cout << " Empty Linked List" << endl;
                return;
            }
            if(this->tail->next == NULL){
                cout << tail->data << endl;
                return;
            }
            Node* temp = tail->next;
            while(count < len){
                cout << temp->data << " ";
                count++;
                temp = temp->next;
            }cout << endl;
            return;
        }
};


int main(){
    CircularLinkedList C;
    // C.InsertAtData(1,4);     // Outputs 'Insertion not possible\nEmpty Circular Linked List
    C.InsertAtHead(1);
    // C.Print();      // 1
    C.InsertAtTail(2);
    // C.Print();      // 1 2
    C.InsertAtData(3,1);
    // C.Print();      // 1 3 2
    // C.InsertAtData(5,6);    // outputs 'Data not found'
    // C.Print();
    C.InsertAtHead(4);
    C.InsertAtTail(6);
    C.Print();      // 4 1 3 2 6
    C.DeleteAtHead();
    C.Print();      // 1 3 2 6
    C.DeleteAtTail();
    C.Print();      // 1 3 2
    return 0;
}
/*
Question Link:: https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next,*prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

vector<pair<int,int>> SumPair(Node* head,int targetSum){
    Node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    vector<pair<int,int>> answer;
    int sum = 0;
    while(head != tail && head->next != tail){
        sum = head->data + tail->data;
        if(sum == targetSum){
            answer.push_back(pair(head->data,tail->data));
            tail = tail->prev;
            head = head->next;
        }else{
            if(sum > targetSum){
                tail = tail->prev;
            }else{
                head = head->next;
            }
        }
    }
    return answer;
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(4);
    Node* n4 = new Node(5);
    Node* n5 = new Node(6);
    Node* n6 = new Node(8);
    Node* n7 = new Node(9);

    Node* h1 = n1;

    n1->next = n2;
    
    n2->next = n3;
    n2->prev = n1;

    n3->next = n4;
    n3->prev = n2;

    n4->next = n5;
    n4->prev = n3;

    n5->next = n6;
    n5->prev = n4;

    n6->next = n7;
    n6->prev = n5;

    n7->prev = n6;

    vector<pair<int,int>> answer;

    answer = SumPair(h1,7);
    cout << "Pairs::" << endl;
    for(auto i: answer){
        cout << "(" << i.first << "," << i.second << ")" << endl;
    }
    return 0;
}
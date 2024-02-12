#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(){
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void leftTraverse(Node* root, vector<int>& leftPart){
    if(root->left == NULL && root->right == NULL){
        // Leaf Node
        return;
    }
    leftPart.push_back(root->data);
    if(root->left){
        leftTraverse(root->left,leftPart);
    }else{
        leftTraverse(root->right,leftPart);
    }
    return;
}

int main(){
    Node* root;
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n4->left = n6;
    n3->left = n7;
    n3->right = n8;
    root = n1;
    vector<int> left;
    leftTraverse(root,left);
    for(auto i:left){
        cout << i << endl;
    }
}
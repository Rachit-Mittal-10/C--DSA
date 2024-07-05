#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(){
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int input){
        data = input;
        left = NULL;
        right = NULL;
    }
};

class Binary_Search_Tree{
    Node *root;
    public:
        Binary_Search_Tree(){
            // Creation of Empty Tree
            root = NULL;
        }
        void Insert(int input){
            Node *NewNode = new Node(input);
            Node *temp = root;
            Node *prev = NULL;
            if(root == NULL){
                root = NewNode;
                return;
            }
            while(temp){
                prev = temp;
                if(NewNode->data <= temp->data){
                    temp = temp->left;
                }else{
                    temp = temp->right;
                }
            }
            if(NewNode->data <= prev->data){
                prev->left = NewNode;
            }else{
                prev->right = NewNode;
            }
        }
        void LevelOrder(){
            if(root == NULL){
                return;
            }
            queue<Node*> Q;
            Q.push(root);
            while(!Q.empty()){
                Node * current = Q.front();
                cout << current->data << " ";
                if(current->left != NULL){
                    Q.push(current->left);
                }
                if(current->right != NULL){
                    Q.push(current->right);
                }
                Q.pop();
            }cout << endl;
        }
        void InOrder(){
            if(root == NULL) return;
            InOrder(root->left);
            cout << root->data << " ";
            InOrder(root->right);
            cout << endl;
        }
        void InOrder(Node *address){
            if(address == NULL) return;
            this->InOrder(address->left);
            cout << address->data << " ";
            this->InOrder(address->right);

        }
        void PreOrder(){
            if(root == NULL) return;
            cout << root->data << " ";
            PreOrder(root->left);
            PreOrder(root->right);
            cout << endl;
        }
        void PreOrder(Node *address){
            if(address == NULL) return;
            cout << address->data << " ";
            this->PreOrder(address->left);
            this->PreOrder(address->right);

        }
        void PostOrder(){
            if(root == NULL) return;
            PostOrder(root->left);
            PostOrder(root->right);
            cout << root->data << " ";
            cout << endl;
        }
        void PostOrder(Node *address){
            if(address == NULL) return;
            this->PostOrder(address->left);
            this->PostOrder(address->right);
            cout << address->data << " ";
        }
        void Search(int input){
            if(root == NULL){
                return;
            }
            Node* returnee = Search_Address(input);
            if(returnee == NULL){
                cout << "Element Not Found" << endl;
                return;
            }
            cout << returnee << endl;
        }
        Node* Search_Address(int input){
            if(root == NULL) return NULL;
            if(input == root->data) return root;
            else if(input < root->data){
                return Search_Address(root->left, input);
            }else if(input > root->data){
                return Search_Address(root->right, input);
            }
            return NULL;
        }
        Node* Search_Address(Node* address, int input){
            if(address == NULL) return NULL;
            if(input == address->data) return address;
            else if(input < address->data){
                return Search_Address(address->left, input);
            }else if(input > address->data){
                return Search_Address(address->right, input);
            }
            return NULL;
        }
        void Delete(int input){
            if(root == NULL){
                return;
            }
            Node *returnee = Search_Address(root, input);
            if(returnee == NULL){
                cout << "Element not in the BST to delete" << endl;
                return;
            }
            root = Delete(input, root);

        }
        Node* Delete(int input, Node *address){
            if(address == NULL) return address;
            if(input < address->data){
                address->left = Delete(input,address->left);
            }else if(input > address->data){
                address->right = Delete(input, address->right);
            }else{
                // Case1: No Child
                if(address->left == NULL && address->right == NULL){
                    delete address;
                    return NULL;
                // Case2.1:  Only Right Child
                }else if(address->left == NULL){
                    Node *temp = address;
                    address = address->right;
                    delete temp;
                    return address;
                // Case2.2: Only Left Child
                }else if(address->right == NULL){
                    Node *temp = address;
                    address = address->left;
                    delete temp;
                    return address;
                }
                // Case3: Two Child
                Node* temp = address->right;
                while(temp->left){
                    temp = temp->left;
                }
                address->data = temp->data;
                address->right->left = Delete(temp->data, temp);
            }
            return address;
        }
};

int main(){
    Binary_Search_Tree B;
    B.Insert(10);
    B.Insert(8);
    B.Insert(12);
    B.Insert(9);
    B.Insert(7);
    B.Insert(11);
    B.Insert(13);
    B.InOrder();
    B.Search(13);
    B.Search(14);
    B.InOrder();
    B.Delete(10);
    B.InOrder();
    B.Delete(10);
    return 0;
}
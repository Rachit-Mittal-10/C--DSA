#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;

    Node(){
        data = 0;
        left = right = NULL;
    }

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    pair<bool,int> SumTree(Node* root){
        if(root == NULL){
            return {true,0};
        }
        
        if(root->left == NULL && root->right == NULL){
            // Leaf Nodes
            return {true,root->data};
        }
        
        pair<bool,int> left = SumTree(root->left);
        pair<bool,int> right = SumTree(root->right);
        int sum_ = left.second + right.second;
        bool cond = (sum_ == root->data) && left.first && right.first;
        return {cond,sum_};
        
    }
public:
    bool isSumTree(Node* root)
    {
         // Your code here
        return SumTree(root).first;
    }
};

int main(){
    Node *n1,*n2,*n3;
    n1 = new Node(5);
    n2 = new Node(2);
    n3 = new Node(3);
    n1->left = n2;
    n1->right = n3;
    Node *r1 = n1;
    Solution S;
    cout << boolalpha << S.isSumTree(r1) << endl;
    return 0;
}
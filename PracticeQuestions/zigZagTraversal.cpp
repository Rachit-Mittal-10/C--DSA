#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int x = 0){
            data = x;
            left = NULL;
            right = NULL;
        }
};

vector<int> zigZagTraversal(Node *root)
{
    // Code here
    vector<int> answer;
    if (root == NULL)
    {
        return answer;
    }

    queue<Node *> q;
    bool LeftToRight = false;
    q.push(root);
    LeftToRight = true;

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            continue;
        }
        answer.push_back(temp->data);
        if (LeftToRight)
        {
            q.push(temp->right);
            q.push(temp->left);
            LeftToRight = false;
        }
        else
        {
            q.push(temp->left);
            q.push(temp->right);
            LeftToRight = true;
        }
    }
    return answer;
}


int main(){
    Node* n1 = new Node(3);
    Node* n2 = new Node(2);
    Node* n3 = new Node(1);

    n1->left = n2;
    n1->right = n3;

    vector<int> answer = zigZagTraversal(n1);
}
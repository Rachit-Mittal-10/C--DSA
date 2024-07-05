#include<bits/stdc++.h>
#include<D:\C++\Print.hpp>
using namespace std;

class Node{
	public:
		int data;
		Node *left,*right;
		Node(int x){
			data = x;
			left = right = NULL;
		}
};

vector<int> MorrisTraversal_inOrder(Node* root){
	vector<int> inOrder;
	if(root == NULL){
		return;
	}
	Node* curr = root;
	Node* pred;
	while(curr != NULL){
		if(curr->left == NULL){
			inOrder.push_back(curr->data);
			curr = curr->right;
		}else{
			pred = curr->left;
			while(pred->right != NULL && pred->right != curr){
				pred = pred->right;
			}
			if(pred->right == NULL){
				pred->right = curr;
				curr = curr->left;
			}else{
				pred->right = NULL;
				inOrder.push_back(curr->data);
				curr = curr->right;
			}
		}
	}
	return inOrder;
}

vector<int> MorrisTraversal_preOrder(Node* root){
	vector<int> preOrder;
	if(root == NULL){
		return preOrder;
	}
	Node* curr = root;
	Node* pred;
	while(curr != NULL){
		if(curr->left == NULL){
			preOrder.push_back(curr->data);
			curr = curr->right;
		}else{
			pred = curr->left;
			while(pred->right != NULL && pred->right != curr){
				pred = pred->right;
			}
			if(pred->right == NULL){
				preOrder.push_back(curr->data);
				pred->right = curr;
				curr = curr->left;
			}else{
				pred->right = NULL;
				curr = curr->right;
			}
		}
	}
	return preOrder;
}

vector<int> MorrisTraversal_postOrder(Node* root){
	vector<int> postOrder;
	if(root == NULL){
		return postOrder;
	}
	Node* curr = root;
	Node* pred;
	while(curr != NULL){
		if(curr->right == NULL){
			postOrder.push_back(curr->data);
			curr = curr->left;
		}else{
			pred = curr->right;
			while(pred->left != NULL && pred->left != curr){
				pred = pred->left;
			}
			if(pred->left == NULL){
				postOrder.push_back(curr->data);
				pred->left = curr;
				curr = curr->right;
			}else{
				pred->left = NULL;
				curr = curr->left;
			}
		}
	}
	reverse(postOrder.begin(),postOrder.end());
	return postOrder;
}

int main(){
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	Node* n6 = new Node(6);
	Node* n7 = new Node(7);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n4->right = n7;
	n3->right = n6;

	Node *root = n1;
	vector<int> inOrder,preOrder,postOrder;
	inOrder = MorrisTraversal_inOrder(root);
	preOrder = MorrisTraversal_preOrder(root);
	postOrder = MorrisTraversal_postOrder();

	Print(inOrder);
	Print(preOrder);
	Print(postOrder);
	return 0;
}
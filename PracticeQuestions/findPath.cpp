#include <bits/stdc++.h>
using namespace std;

// Finds the apth to a particular node in the Tree

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

void findPath(Node *root, int node, vector<int> &path)
{
	if (root == NULL)
	{
		return;
	}

	path.push_back(root->data);

	if (root->data == node)
	{
		return;
	}

	findPath(root->left, node, path);
	findPath(root->right, node, path);
	if (!path.empty())
		path.pop_back();
}

int main()
{
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);
	Node *n5 = new Node(5);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;

	Node *root = n1;

	vector<int> path;
	findPath(root, 4, path);
	return 0;
}
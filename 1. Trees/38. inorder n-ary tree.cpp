// Approach: The inorder traversal of an N-ary tree is defined as visiting all the children except the last then the root
//  and finally the last child recursively. 

// Recursively visit the first child.
// Recursively visit the second child.
// …..
// Recursively visit the second last child.
// Print the data in the node.
// Recursively visit the last child.
// Repeat the above steps till all the nodes are visited.
// Below is the implementation of the above approach: 

// C++ implementation of the approach
// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<set>
#include<unordered_set>
#include<stack>
#include<map>
using namespace std;

// Class for the node of the tree
struct Node
{
	int data;

	// List of children
	struct Node **children;
	
	int length;
	
	Node()
	{
		length = 0;
		data = 0;
	}

	Node(int n, int data_)
	{
		children = new Node*();
		length = n;
		data = data_;
	}
};

// Function to print the inorder traversal
// of the n-ary tree
void inorder(Node *node)
{
	if (node == NULL)
		return;

	// Total children count
	int total = node->length;
	
	// All the children except the last
	for (int i = 0; i < total - 1; i++)
		inorder(node->children[i]);

	// Print the current node's data
	cout<< node->data << " ";

	// Last child
	inorder(node->children[total - 1]);
}

// Driver code
int main()
{

	/* Create the following tree
		1
		/ | \
		2 3 4
		/ | \
		5 6 7
	*/
	int n = 3;
	Node* root = new Node(n, 1);
	root->children[0] = new Node(n, 2);
	root->children[1] = new Node(n, 3);
	root->children[2] = new Node(n, 4);
	root->children[0]->children[0] = new Node(n, 5);
	root->children[0]->children[1] = new Node(n, 6);
	root->children[0]->children[2] = new Node(n, 7);

	inorder(root);
	return 0;
}

// This code is Contributed by Arnab Kundu

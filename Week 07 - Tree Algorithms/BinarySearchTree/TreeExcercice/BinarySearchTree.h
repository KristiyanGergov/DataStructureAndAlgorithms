#pragma once

#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int data_)
	{
		left = NULL;
		right = NULL;
		data = data_;
	}

	~Node()
	{
		delete left;
		delete right;
	}
};


class BinarySearchTree
{
private:
	Node* head;

public:
	BinarySearchTree();
	~BinarySearchTree();

	void insert(int value);

	// DFS
	void preOrder(Node* root);
	void inOrder(Node* root);
	void postOrder(Node* root);

	// BFS
	void levelOrder(Node* root);
};
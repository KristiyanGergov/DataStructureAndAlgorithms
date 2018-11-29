#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	this->head = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
	delete head;
}

void BinarySearchTree::insert(int data)
{
	if (head == NULL)
	{
		head = new Node(data);
		return;
	}

	Node * curr = head;
	Node * temp = new Node(data);

	while (curr != nullptr)
	{
		if (data > curr->data)
		{
			if (curr->right == NULL)
			{
				curr->right = temp;
				break;
			}
			curr = curr->right;
		}
		else if (data < curr->data)
		{
			if (curr->left == NULL)
			{
				curr->left = temp;
				break;
			}
			curr = curr->left;
		}
		else
		{
			return;
		}
	}
}

void BinarySearchTree::inOrder(Node* root) 
{
	if (root == NULL)
		return;

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void BinarySearchTree::postOrder(Node* root) 
{
	if (root == NULL)
		return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

void BinarySearchTree::preOrder(Node* root) 
{
	if (root == NULL)
		return;
	
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}


void BinarySearchTree::levelOrder(Node* root)
{

}
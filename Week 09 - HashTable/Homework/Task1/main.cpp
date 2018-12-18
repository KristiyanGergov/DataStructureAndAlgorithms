#include <iostream>
using namespace std;

struct node
{
	long long key;
	node *left, *right;
};

node *newNode(long long item)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
int counter = 0;

node* insert(node* node, long long key)
{
	if (node == NULL)
	{
		counter++;
		return newNode(key);
	}
	if (key < node->key)
	{
		node->left = insert(node->left, key);
	}
	else if (key > node->key)
	{
		node->right = insert(node->right, key);
	}
	return node;
}

int main() {

	int n;

	cin >> n;
	node *root = NULL;

	for (int i = 0; i < n; i++)
	{
		long long curr;
		cin >> curr;
		root = insert(root, curr);
	}

	cout << counter;

	return 0;
}
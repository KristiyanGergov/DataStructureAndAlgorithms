#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Node
{
	double value;
	Node *left;
	Node *right;
	int height;

	Node(double value, Node *left, Node *right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}
};

class AVLTree
{
private:
	Node *root;

	bool containsRecursive(Node *current, double value)
	{
		if (current == NULL)
		{
			return false;
		}

		if (current->value == value)
		{
			return true;
		}

		if (value < current->value)
		{
			return containsRecursive(current->left, value);
		}
		else
		{
			return containsRecursive(current->right, value);
		}
	}

	void printRecursive(Node *current)
	{
		if (current == NULL)
		{
			return;
		}

		printRecursive(current->left);
		cout << current->value << " ";
		printRecursive(current->right);
	}

public:
	AVLTree()
	{
		root = NULL;
	}

	int height(Node *N)
	{
		if (N == NULL)
			return 0;
		return N->height;
	}


	Node *rightRotate(Node *y)
	{
		Node *x = y->left;
		Node *T2 = x->right;

		x->right = y;
		y->left = T2;

		y->height = max(height(y->left), height(y->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;

		return x;
	}

	Node *leftRotate(Node *x)
	{
		Node *y = x->right;
		Node *T2 = y->left;

		y->left = x;
		x->right = T2;

		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;

		return y;
	}

	int getBalance(Node *N)
	{
		if (N == NULL || N->left == NULL || N->right == NULL)
			return 0;
		return height(N->left) - height(N->right);
	}

	struct Node* newNode(double key)
	{
		Node* node = new Node(key, NULL, NULL);
		node->height = 1;
		return(node);
	}

	void add(double value)
	{
		root = insert(root, value);
	}

	Node* insert(Node* node, double key)
	{

		if (root == NULL)
		{
			return root;
		}

		if (node == NULL) {
			return newNode(key);
		}

		if (key < node->value)
			node->left = insert(node->left, key);
		else if (key > node->value)
			node->right = insert(node->right, key);
		else {
			cout << key << " already added" << endl;
			return node;
		}
		node->height = 1 + max(height(node->left),
			height(node->right));

		int balance = getBalance(node);

		if (balance > 1 && key < node->left->value)
			return rightRotate(node);

		if (balance < -1 && key > node->right->value)
			return leftRotate(node);

		if (balance > 1 && key > node->left->value)
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		if (balance < -1 && key < node->right->value)
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		return node;
	}

	void remove(double value)
	{
		if (!contains(value)) {
			cout << value << " not found to remove" << endl;
			return;
		}
		root = deleteNode(root, value);
	}

	Node* deleteNode(Node* root, double key)
	{
		if (root == NULL)
			return root;
		
		if (key < root->value)
			root->left = deleteNode(root->left, key);

		else if (key > root->value)
			root->right = deleteNode(root->right, key);

		else
		{
			if ((root->left == NULL) || (root->right == NULL))
			{
				Node *temp = root->left ? root->left : root->right;

				if (temp == NULL)
				{
					temp = root;
					root = NULL;
				}
				else
					*root = *temp;

				free(temp);
			}
			else
			{
				Node* temp = minValueNode(root->right);

				root->value = temp->value;

				root->right = deleteNode(root->right, temp->value);
			}
		}

		if (root == NULL)
			return root;

		root->height = 1 + max(height(root->left),
			height(root->right));

		int balance = getBalance(root);

		if (balance > 1 && getBalance(root->left) >= 0)
			return rightRotate(root);

		if (balance > 1 && getBalance(root->left) < 0)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		if (balance < -1 && getBalance(root->right) <= 0)
			return leftRotate(root);

		if (balance < -1 && getBalance(root->right) > 0)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}

	Node * minValueNode(Node* node)
	{
		Node* current = node;

		while (current->left != NULL)
			current = current->left;

		return current;
	}

	bool contains(double value)
	{
		if (root == NULL)
		{
			return false;
		}

		return containsRecursive(root, value);
	}

	void print()
	{
		if (root == NULL)
		{
			return;
		}

		printRecursive(root);
		cout << endl;
	}
};

int main()
{
	AVLTree tree;
	string operation;
	double number;
	int N;

	cin >> N;
	cout << fixed;

	for (size_t i = 0; i < N; i++)
	{
		cin >> operation;
		if (operation != "print")
		{
			cin >> number;
		}

		if (operation == "add")
		{
			tree.add(number);
		}
		else if (operation == "remove")
		{
			tree.remove(number);
		}
		else if (operation == "contains")
		{
			if (tree.contains(number))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" << endl;
			}
		}
		else if (operation == "print")
		{
			tree.print();
		}
	}

	return 0;
}
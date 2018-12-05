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

	int height(struct Node *N)
	{
		if (N == NULL)
			return 0;
		return N->height;
	}


	struct Node *rightRotate(struct Node *y)
	{
		struct Node *x = y->left;
		struct Node *T2 = x->right;

		x->right = y;
		y->left = T2;

		y->height = max(height(y->left), height(y->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;

		return x;
	}

	struct Node *leftRotate(struct Node *x)
	{
		struct Node *y = x->right;
		struct Node *T2 = y->left;

		y->left = x;
		x->right = T2;

		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;

		return y;
	}

	int getBalance(Node *N)
	{
		if (N == NULL)
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
		if (root == NULL)
		{
			root = new Node(value, NULL, NULL);
			root->height = 1;
			return;
		}

		Node* curr = root;
		Node* temp = new Node(value, NULL, NULL);

		while (curr != NULL)
		{
			if (value < curr->value)
			{
				if (curr->left == NULL)
				{
					curr->left = temp;
					break;
				}
				curr = curr->left;
			}
			else if (value > curr->value)
			{
				if (curr->right == NULL)
				{
					curr->right = temp;
					break;
				}
				curr = curr->right;
			}
			else
			{
				cout << value << " already added" << endl;
				return;
			}
		}

		curr->height = 1 + max(height(curr->left),
			height(curr->right));

		int balance = getBalance(curr);

		if (balance > 1 && value < curr->left->value)
			curr = rightRotate(root);

		if (balance < -1 && value > curr->right->value)
			curr = leftRotate(curr);

		if (balance > 1 && value > curr->left->value)
		{
			curr->left = leftRotate(curr->left);
			curr = rightRotate(curr);
		}

		if (balance < -1 && value < curr->right->value)
		{
			curr->right = rightRotate(curr->right);
			curr = leftRotate(root);
		}

		return;
	}


	void remove(double value)
	{

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
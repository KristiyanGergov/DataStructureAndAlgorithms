#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};
class BinarySearchTree
{

public:
	BinarySearchTree()
	{
		root = nullptr;
	}
	void insert(int value)
	{
		if (root == nullptr)
		{
			root = new Node(value);
			return;
		}
		Node* curr = root;
		Node* temp = new Node(value);
		while (curr != nullptr)
		{
			if (value < curr->data)
			{
				if (curr->left == NULL)
				{
					curr->left = temp;
					break;
				}
				else
				{
					curr = curr->left;
				}
			}
			else if (value > curr->data)
			{
				if (curr->right == NULL)
				{
					curr->right = temp;
					break;
				}
				else
				{
					curr = curr->right;
				}
			}
			else
			{
				return;
			}
		}
	}
	void preorder()
	{
		preorder(root);
	}
	void postorder()
	{
		postorder(root);
	}
	void inorder()
	{
		inorder(root);
	}
	bool search(int key)
	{
		if (root == nullptr) return false;
		if (root->data == key)
		{
			return true;
		}
		else if (key < root->data)
		{
			root = root->left;
			return search(key);
		}
		else
		{
			root = root->right;
			return search(key);
		}
	}
	int height()
	{
		return heightN(this->root);
	}
	int countNodes()
	{
		return nodesCount(this->root, 0);
	}
	Node*  deleteElR(int key)
	{
		return deleteEl(root, key);
	}
	void LeverOrder() {
		return print(root);
	}

private:
	Node * root;
	void inorder(Node* root)
	{
		if (root == nullptr)
			return;
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
	void preorder(Node* root)
	{
		if (root == nullptr)
			return;

		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
	void postorder(Node* root)
	{

		if (root == nullptr)
			return;
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
	int nodesCount(Node *root, int count)
	{

		if (root == nullptr)
			return count;

		count++;
		nodesCount(root->left, count);
		nodesCount(root->right, count);
	}
	int heightN(Node *root)
	{
		if (root == nullptr)
		{
			return -1;
		}
		else
		{

			int Lheight = heightN(root->left);
			int Rheight = heightN(root->right);

			if (Lheight > Rheight)
			{
				return(Lheight + 1);
			}
			else return (Rheight + 1);
		}
	}
	Node* findMin(Node* root)
	{
		while (root->left != nullptr)
		{
			root = root->left;
		}
		return root;
	}

	Node* deleteEl(Node *root, int data)
	{
		if (root != nullptr)
		{
			if (data < root->data) root->left = deleteEl(root->left, data);
			else if (data > root->data) root->right = deleteEl(root->right, data);
			else
			{
				if (root->left == nullptr && root->right == nullptr)
				{
					delete root;
					root = nullptr;
				}
				else if (root->left == nullptr)
				{
					struct Node *temp = root;
					root = root->right;
					delete temp;
				}
				else if (root->right == nullptr)
				{
					struct Node *temp = root;
					root = root->left;
					delete temp;
				}
				else
				{
					struct Node *temp = findMin(root->right);
					root->data = temp->data;
					root->right = deleteEl(root->right, temp->data);
				}
			}
		}
		return root;
	}

	void printLevel(Node* root, int level) {
		if (!root) return;
		if (level == 0) {
			cout << root->data << " ";
			return;
		}
		printLevel(root->left, level - 1);
		printLevel(root->right, level - 1);
	}
	void print(Node* root) {
		int h = heightN(root);

		for (int i = 0; i <= h; i++) {
			printLevel(root, i);
		}
		cout << endl;
	}
};
int main()
{
	BinarySearchTree binaryTree;
	int n;
	while (cin >> n)
	{
		binaryTree.insert(n);
	}
	binaryTree.inorder();
	cout << endl;
	binaryTree.postorder();
	cout << endl;
	binaryTree.preorder();
	cout << endl;
	cout << binaryTree.height() << endl;
	cout << binaryTree.countNodes() << endl;
	binaryTree.deleteElR(5);
	binaryTree.LeverOrder();
	return 0;
}

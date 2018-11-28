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
class BST
{

public:
	BST()
	{
		root = nullptr;
	}
	void insertEl(int value)
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
	bool Search(int key)
	{
		if (root == nullptr) return false;
		if (root->data == key)
		{
			return true;
		}
		else if (key < root->data)
		{
			root = root->left;
			return Search(key);
		}
		else
		{
			root = root->right;
			return Search(key);
		}
	}
	int height()
	{
		return heightN(this->root);
	}
	int countNodes()
	{
		int n = 0;
		return nodesCount(this->root, n);
	}
	Node*  DeleteR(int key)
	{
		return Delete(root, key);
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
	int nodesCount(Node *root, int &count)
	{

		if (root != nullptr)//if we are not at a leaf
		{
			count++;
			nodesCount(root->left, count);//recurisvly call the function and increment the count
			nodesCount(root->right, count);
		}
		else
		{
			return count;//return the count
		}

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
	Node* FindMin(Node* root)
	{
		while (root->left != nullptr)
		{
			root = root->left;
		}
		return root;
	}

	Node* Delete(Node *root, int data)
	{
		if (root != nullptr)
		{
			if (data < root->data) root->left = Delete(root->left, data);
			else if (data > root->data) root->right = Delete(root->right, data);
			else
			{
				// Case 1:  No child
				if (root->left == nullptr && root->right == nullptr)
				{
					delete root;
					root = nullptr;
				}
				//Case 2: One child
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
				// case 3: 2 children
				else
				{
					struct Node *temp = FindMin(root->right);
					root->data = temp->data;
					root->right = Delete(root->right, temp->data);
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
	BST t;
	int n;
	while (cin >> n)
	{
		t.insertEl(n);
	}
	t.inorder();
	cout << endl;
	t.postorder();
	cout << endl;
	t.preorder();
	cout << endl;
	cout << t.height() << endl;
	cout << t.countNodes() << endl;
	t.DeleteR(5);
	t.LeverOrder();
	return 0;
}

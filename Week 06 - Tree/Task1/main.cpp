#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

class Solution {
public:
	Node* insert(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		}
		else {
			Node* cur;
			if (data <= root->data) {
				cur = insert(root->left, data);
				root->left = cur;
			}
			else {
				cur = insert(root->right, data);
				root->right = cur;
			}

			return root;
		}
	}


	int height(Node* root) {
	
		int a = NULL;

		if (root == NULL)
			return -1;

		int left = height(root->left);
		int right = height(root->right);

		if (left > right)
			return ++left;
		else
			return ++right;
	}
};

int main() {

	int* arr = new int[5];

	arr[-1] = 4;
	arr[-2] = 3;


	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0) {
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	int height = myTree.height(root);

	std::cout << height;

	return 0;
}
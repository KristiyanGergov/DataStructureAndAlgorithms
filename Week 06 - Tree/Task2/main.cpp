#include <iostream>
#include <queue>
#include <map>

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
	void topView(Node * root) {

		if (root == NULL)
			return;

		queue<Node*>q;
		map<int, int> m;
		int hdLeft = 0;
		int hdRight = 0;

		q.push(root);

		while (q.size())
		{
			if (m.count(hdLeft) == 0 || m.count(hdRight) == 0)
				m[hdLeft] = root->data;
			if (root->left)
			{
				hdLeft = hdLeft - 1;
				q.push(root->left);
			}
			if (root->right)
			{
				hdRight = hdRight + 1;
				q.push(root->right);
			}
			q.pop();
			
			if (q.size() > 0)
				root = q.front();

		}

		for (auto i = m.begin(); i != m.end(); i++)
		{
			cout << i->second << " ";
		}

	}
};

int main() {

	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0) {
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	myTree.topView(root);
	return 0;
}
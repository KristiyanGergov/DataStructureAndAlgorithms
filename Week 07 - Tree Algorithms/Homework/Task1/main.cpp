#include <iostream>
#include <map>
#include <queue>
#include <iomanip>

using namespace std;

struct Node {
	int data;
	int level;
	Node* left;
	Node* right;
	Node(int data, int level) {
		this->data = data;
		this->level = level;
		this->left = NULL;
		this->right = NULL;
	}

};

class Tree {
public:
	int level = 0;
	queue<Node*> levels;


	Node* insert(Node* root, int data) {
		if (root == NULL)
		{
			Node* result = new Node(data, level);
			levels.push(result);
			return result;
		}
		else
		{
			Node* curr;
			this->level = root->level + 1;

			if (data < root->data)
			{
				curr = insert(root->left, data);
				root->left = curr;
			}
			else
			{
				curr = insert(root->right, data);
				root->right = curr;
			}

			return root;
		}
	}
};


int main() {

	Tree myTree;
	Node* root = NULL;

	int n;
	int data;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> data;
		root = myTree.insert(root, data);
	}

	map<int, int> levelsSum;
	map<int, int> childsSum;

	while (!myTree.levels.empty())
	{
		Node* curr = myTree.levels.front();

		if (levelsSum.find(curr->level) == levelsSum.end()) {
			levelsSum.insert(make_pair(curr->level, curr->data));
			childsSum.insert(make_pair(curr->level, 1));
		}
		else {
			levelsSum[curr->level] += curr->data;
			childsSum[curr->level] += 1;
		}

		myTree.levels.pop();
	}

	for (int i = 0; i < levelsSum.size(); i++)
	{
		cout << setprecision(2) << fixed << (double)levelsSum[i] / childsSum[i] << endl;
	}

	return 0;
}
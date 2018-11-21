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
	Node * insert(Node* root, int data) {
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
	void verticalTraversal(Node* head, map<int, int> &levelMap, int level) {
		if (head == NULL)
			return;
		if (levelMap.count(level) == 0)
			levelMap[level] = head->data;

		if (level == 0 || level < 0)
		{
			verticalTraversal(head->left, levelMap, level - 1);
		}
		if (level == 0 || level > 0)
		{
			verticalTraversal(head->right, levelMap, level + 1);
		}
	}

	void findTheRest(Node* head, map<int, int> &levelMap, int level, bool lastLeft) {
		if (head == NULL)
			return;
		if (levelMap.count(level) == 0)
			levelMap[level] = head->data;

		if (lastLeft)
		{
			findTheRest(head->left, levelMap, level - 1, true);
			findTheRest(head->right, levelMap, level + 1, false);
		}
		else
		{
			findTheRest(head->right, levelMap, level + 1, false);
			findTheRest(head->left, levelMap, level - 1, true);
		}
	}


	void topView(Node * root) {
		if (root == NULL)
			return;

		map<int, int> levelMap;
		verticalTraversal(root, levelMap, 0);
		findTheRest(root, levelMap, 0, true);

		for (map<int, int>::iterator it = levelMap.begin(); it != levelMap.end(); ++it) {
			cout << it->second << ' ';
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
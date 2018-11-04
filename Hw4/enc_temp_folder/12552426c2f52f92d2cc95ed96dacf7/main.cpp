#include <iostream>
#include <string>
using namespace std;

struct Node {
	bool initialized;
	int data;
	Node* next;
};

class LinkedList {
private:
	Node head;
public:
	void add(int data);
	int getAt(int index);
};

void LinkedList::add(int curr)
{
	Node* temp = new Node();
	temp->data = curr;
	temp->next = nullptr;
	temp->initialized = true;

	if (!this->head.initialized)
	{
		this->head = *temp;
		this->head.next = nullptr;
	}
	else
	{
		Node* curr = &head;
		bool t = curr->next;
		while (t && curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next = temp;
	}
	delete[] temp;
}

int LinkedList::getAt(int index)
{
	Node curr = head;
	for (int i = 0; i < index; i++)
	{
		if (curr.next != nullptr)
			curr = *curr.next;
		else
			return -1;
	}
	return curr.data;
}

int main() {
	string input1;
	LinkedList list = LinkedList();
	while (getline(cin, input1))
	{
		if (input1.empty())
			break;
		int curr = stoi(input1);
		list.add(curr);
	}

	int f = list.getAt(0);
	int s = list.getAt(1);
	int t = list.getAt(2);

	return 0;
}
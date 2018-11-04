#include <iostream>
#include <string>
using namespace std;

class Node {
private:
	bool initialized;
	int data;
	Node* next;
public:
	int getData();
	bool getInitialized();
	Node* getNext();
	
	void setData(const int);
	void setInitialized(const bool);
	void setNext(Node*);
};

class LinkedList {
private:
	Node head;
	int size;
public:
	void add(int data);
	int getAt(int index);
	int getSize();
};

void LinkedList::add(int curr)
{
	size++;
	Node* temp = new Node();
	temp->setData(curr);
	temp->setNext(nullptr);
	temp->setInitialized(true);

	if (!this->head.getInitialized())
	{
		this->head = *temp;
		this->head.setNext(nullptr);
	}
	else
	{
		Node* curr = &head;
		
		while (curr && curr->getNext() != nullptr)
			curr = curr->getNext();
		
		curr->setNext(temp);
	}
}

int LinkedList::getAt(int index)
{
	Node curr = head;
	for (int i = 0; i < index; i++)
	{
		if (curr.getNext() != nullptr)
			curr = *curr.getNext();
		else
			return -1;
	}
	return curr.getData();
}

int LinkedList::getSize()
{
	return this->size;
}

int main() {
	string input;
	LinkedList list = LinkedList();

	while (getline(cin, input))
	{
		if (input.empty())
			break;
		int curr = stoi(input);
		list.add(curr);
	}

	int min = INT32_MAX;
	int max = INT32_MIN;
	int sum = 0;
	
	for (int i = 0; i < list.getSize(); i++)
	{
		int current = list.getAt(i);
		if (current <= min)
		{
			min = current;
		}
		if (current >= max)
		{
			max = current;
		}
		sum += current;
	}

	cout << min << " ";
	cout << max << " ";
	cout << sum << " ";

	return 0;
}

int Node::getData()
{
	return this->data;
}

bool Node::getInitialized()
{
	return this->initialized;
}

Node * Node::getNext()
{
	return this->next;
}

void Node::setData(const int data)
{
	this->data = data;
}

void Node::setInitialized(const bool initialized)
{
	this->initialized = initialized;
}

void Node::setNext(Node * next)
{
	this->next = next;
}
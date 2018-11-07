#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
	int data;
	Node* next;
	bool initialized;
};

class Pair {
private:
	int first;
	int second;
public:
	Pair(int, int);
	int getFirst();
	int getSecond();
	bool operator==(const Pair& other);
};

class LinkedList {
private:
	Node head;
	Node tail;
	int size;
public:
	void add(int data);
	int getAt(int index);
	int getSize();
};

void LinkedList::add(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->next = nullptr;
	temp->initialized = true;
	this->size++;
	if (head.initialized)
	{
		Node* curr = &head;
		while (curr->next)
			curr = curr->next;

		curr->next = temp;
		tail = *temp;
	}
	else
	{
		head = *temp;
		tail = *temp;
	}
}

int LinkedList::getAt(int index)
{
	Node curr = head;
	for (int i = 0; i < index; i++)
	{
		if (curr.next)
		{
			curr = *curr.next;
		}
	}
	return curr.data;
}

int LinkedList::getSize()
{
	return this->size;
}


int main() {
	int n;
	LinkedList list = LinkedList();
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		list.add(num);
	}

	int k;
	cin >> k;
	unordered_set<int> set;
	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		if (num < 1235 && num > 0 )
			set.insert(num);
	}

	int counter = 0;
	vector<Pair> pairs;
	for (int i = 0; i < list.getSize() - 1; i++)
	{
		Pair pair = Pair(list.getAt(i), list.getAt(i + 1));
		int pairCount = count(pairs.begin(), pairs.end(), pair);

		if (pairCount > 0)
			continue;
		else
			pairs.push_back(pair);

		int first = pair.getFirst();
		int second = pair.getSecond();

		bool containsFirst = set.find(first) != set.end(); 
		bool containsSecond = set.find(second) != set.end();

		if (containsFirst && containsSecond)
			counter++;
	}

	cout << counter;

	return 0;
}

Pair::Pair(int first, int second)
{
	this->first = first;
	this->second = second;

}

int Pair::getFirst()
{
	return this->first;
}

int Pair::getSecond()
{
	return this->second;
}

bool Pair::operator==(const Pair & pair)
{
	if ((this->first == pair.first && this->second == pair.second) ||
		(this->first == pair.second && this->second == pair.first))
		return true;
	return false;
}

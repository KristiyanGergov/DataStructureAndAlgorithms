#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
struct Node {
	T data;
	Node<T>* next;
	bool initialized;
};

template <typename T>
class LinkedList {
private:
	Node<T> head;
	Node<T> tail;
	int size;
public:
	void add(T data);
	int getAt(int index);
	int getSize();
	int removeLast();
};

template <typename T>
void LinkedList<T>::add(T data)
{
	Node<T>* temp = new Node<T>();
	temp->data = data;
	temp->next = nullptr;
	temp->initialized = true;
	this->size++;
	if (head.initialized)
	{
		Node<T>* curr = &head;
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

template <typename T>
int LinkedList<T>::getAt(int index)
{
	Node<T> curr = head;
	for (int i = 0; i < index; i++)
	{
		if (curr.next)
		{
			curr = *curr.next;
		}
	}
	return curr.data;
}

template <typename T>
int LinkedList<T>::getSize()
{
	return this->size;
}


class SnowMan {
private:
	LinkedList<int> balls;
public:
	LinkedList<int> getBalls();
};

LinkedList<int> SnowMan::getBalls()
{
	return this->balls;
}

template <typename T>
int LinkedList<T>::removeLast()
{
	Node<T>* current;
	Node<T>* previous = nullptr;
	int res = tail.data;
	current = &head;

	while (current->next)
	{
		previous = current;
		current = current->next;
	}

	tail = *previous;
	previous->next->initialized = false;
	tail.next = nullptr;
	delete current;

	return res;
}

int main() {
	int n;
	cin >> n;

	LinkedList<LinkedList<int>> results = LinkedList<LinkedList<int>>();

	LinkedList<int> list = LinkedList<int>();
	list.add(0);
	int result = 0;

	for (int i = 0; i < n; i++)
	{
		int p, m;
		cin >> p;
		cin >> m;

		if (m != 0)
		{
			int test = list.getAt(p) + m;
			list.add(test);
		}
		else
		{
			int test = list.getAt(list.getSize()) - (list.getAt(list.getSize()) - list.getAt(list.getSize() - 2));
			list.add(test);
		}
	}

	return 0;
}


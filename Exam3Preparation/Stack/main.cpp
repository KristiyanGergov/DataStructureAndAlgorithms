#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
class stack {
private:
	int size;
	Node<T>* head;
public:
	stack();
	void push(T data);
	bool pop();
	T top();
	bool empty();
	int getSize();
	void reverse();
};

template<typename T>
stack<T>::stack()
{
	this->size = 0;
}

template<typename T>
void stack<T>::push(T data)
{
	Node<T>* curr = new Node<T>();
	curr->data = data;
	curr->next = head;
	head = curr;
	size++;
}

template<typename T>
bool stack<T>::pop()
{
	if (size == 0)
		return false;

	Node<T>* curr = head;
	head = head->next;
	delete curr;
	size--;
	return true;
}

template<typename T>
T stack<T>::top()
{
	return head->data;
}

template<typename T>
bool stack<T>::empty()
{
	return getSize() == 0;
}

template<typename T>
int stack<T>::getSize()
{
	return this->size;
}

template<typename T>
void stack<T>::reverse()
{
	stack<T>* res = new stack<T>();

	while (this->empty())
	{
		res->push(this->top());
		this->pop();
	}

	while (!res->empty())
	{
		this->push(res->top());
		res->pop();
	}
	delete res;
}

int main() {
	string input = "abcbd";
	stack<char> res = stack<char>();

	for (int i = 0; i < input.length(); i++)
		res.push(input.at(i));

	res.reverse();
	return 0;
}
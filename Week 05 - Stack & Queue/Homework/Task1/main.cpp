#include <iostream>

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
	return this->size == 0;
}

int main() {
	int n;

	cin >> n;

	int addend = 2;
	int size = n;

	stack<int> res;

	res.push(1);
	res.push(n);

	while (size > 1)
	{
		int first = res.top();
		res.pop();
		int second = res.top();
		res.pop();

		if (size % 2 == 0)
			first -= addend / 2;
		else
			second += addend;


		res.push(second);
		res.push(first);

		size /= 2;
		addend *= 2;
	}

	cout << res.top();

	return 0;
}
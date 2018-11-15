#include <iostream>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
class queue {
private:
	int size;
	Node<T>* head;
public:
	queue();
	void push(T data);
	bool pop();
	T top();
	bool empty();
	void reverse();
};

template<typename T>
queue<T>::queue()
{
	this->size = 0;
}

template<typename T>
void queue<T>::push(T data)
{
	Node<T>* curr = new Node<T>();
	curr->data = data;

	if (!head)
	{
		this->head = curr;
	}
	else {
		Node<T>* temp = head;

		while (temp && temp->next)
		{
			temp = temp->next;
		}
		temp->next = curr;
	}
	size++;
}

template<typename T>
bool queue<T>::pop()
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
T queue<T>::top()
{
	return head->data;
}

template<typename T>
bool queue<T>::empty()
{
	return this->size == 0;
}

template<typename T>
void queue<T>::reverse()
{
	Node<T> *current = head;
	Node<T> *prev = nullptr, *next = nullptr;

	while (current)
	{
		next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}

	head = prev;
}

int main() {

	queue<int> res;

	res.push(1);
	res.push(2);
	res.push(3);
	res.push(4);
	res.push(5);

	res.reverse();
	res.pop();

	return 0;
}
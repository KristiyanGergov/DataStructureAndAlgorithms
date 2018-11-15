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
void stack<T>::reverse()
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

template<typename T>
bool stack<T>::empty()
{
	return this->size == 0;
}

int main() {
	stack<int> test;
	test.push(1);
	test.push(2);
	test.push(3);
	test.push(4);

	test.reverse();
	
	return 0;
}
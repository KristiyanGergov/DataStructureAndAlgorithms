template <typename T>
struct Node {
	Node* next;
	Node* prev;
	T data;
};

template <typename T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	int getSize();
	void add(T data);
	bool remove(T index);
	void reverse();
	T get(int index);
};

template<typename T>
int LinkedList<T>::getSize()
{
	return this->size;
}

template<typename T>
void LinkedList<T>::add(T data)
{
	Node<T>* val = new Node<T>();
	val->data = data;
	val->next = nullptr;
	size++;
	if (!head)
	{
		val->prev = nullptr;
		head = val;
		tail = val;
	}
	else
	{
		Node<T>* curr = head;
		while (curr->next)
			curr = curr->next;
		val->prev = curr;
		curr->next = val;
		tail = val;
	}
}

template<typename T>
bool LinkedList<T>::remove(T index)
{
	if (index > size - 1)
		return false;

	Node<T> *curr = head;
	size--;

	if (index == 0)
	{
		head = head->next;
		return true;
	}

	for (int i = 0; i < index - 1; i++)
	{
		curr = curr->next;
	}

	curr->next = curr->next->next;
	curr->next->prev = curr->next;
	return true;
}

template<typename T>
void LinkedList<T>::reverse()
{
	Node<int>* curr = tail;

	while (tail->prev)
	{
		tail->next = tail->prev;
		tail = tail->next;
	}

	tail = head;
	tail->next = nullptr;
}

template<typename T>
T LinkedList<T>::get(int index)
{
	if (index > size - 1)
	{
		return;
	}
	Node<int>* curr = head;
	for (int i = 0; i < index; i++)
	{
		curr = curr->next;
	}
	return curr->data;
}

template<typename T>
LinkedList<T> merge(LinkedList<T> first, LinkedList<T> second) {

	for (int i = 0; i < second.getSize(); i++)
		first.add(second.get(i));

	return first;
}

int main() {
	LinkedList<int> list = LinkedList<int>();

	list.get(0);

	return 0;
}
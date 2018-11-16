#include <iostream>
#include <cstring>
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


const char* white = "white";
const char* green = "green";
const char* blue = "blue";

int main() {
	int n;

	cin >> n;

	stack<long long> whiteStones;

	char* stone = new char[5];

	for (int i = 0; i < n; i++)
	{
		int k;

		cin >> stone;
		cin >> k;

		if (strcmp(stone, white) == 0)
		{
			whiteStones.push(k);
		}
		else if (strcmp(stone, green) == 0) {
			long long sum = 0;

			for (long long i = 0; i < k; i++)
			{
				sum += whiteStones.top();
				whiteStones.pop();
			}
			whiteStones.push(sum);
		}
		else if (strcmp(stone, blue) == 0) {
			long long max = 0;

			for (long long i = 0; i < k; i++)
			{
				if (max < whiteStones.top())
					max = whiteStones.top();
				whiteStones.pop();
			}

			whiteStones.push(max);
		}
	}

	stack<long long> res;
	while (!whiteStones.empty()) 
	{
		res.push(whiteStones.top());
		whiteStones.pop();
	}

	while (!res.empty())
	{
		cout << res.top() << " ";
		res.pop();
	}

	return 0;
}
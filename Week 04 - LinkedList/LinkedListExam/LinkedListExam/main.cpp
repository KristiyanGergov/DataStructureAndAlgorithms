#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Node {
	int data;
	Node* next;
};

class LinkedList {
public:

	LinkedList() {
		this->head = nullptr;
		this->size = 0;
	}

	LinkedList(LinkedList &other) {
		this->head = other.head;
		this->size = other.size;
	}

	void add(int val, int pos) {

		if (pos > size || pos < 0)
		{
			cout << "add_last";
			pos = size;
		}

		this->size++;

		Node* newNode = new Node();
		newNode->data = val;

		if (head == nullptr)
		{
			head = newNode;
			head->next = nullptr;

		}
		else if (pos == 0) {
			Node* curr = head;

			head = newNode;
			newNode->next = curr;
		}
		else
		{
			Node* curr = head;
			for (int i = 0; i < pos - 1; i++)
			{
				curr = curr->next;
			}

			if (curr != nullptr)
			{
				newNode->next = curr->next;
				curr->next = newNode;
			}
		}

	}

	void print() {

		Node * curr = head;
		while (curr)
		{
			cout << curr->data << "#";
			curr = curr->next;
		}

	}

	void remove(int pos) {
		if (pos > size - 1 || pos < 0)
		{
			cout << "remove_failed";
			return;
		}
		Node* curr = head;

		for (int i = 0; i < pos - 1; i++)
		{
			curr = curr->next;
		}

		if (pos == 0)
		{
			if (head->next)
				head = head->next;
			else
				head = nullptr;
		}
		else
		{
			curr->next = curr->next->next;
		}

		this->size--;
	}
	void reverse() {
		Node *current = head;
		Node *prev = nullptr, *next = nullptr;

		while (current)
		{
			next = current->next;

			current->next = prev;

			prev = current;
			current = next;
		}

		head = prev;
	}

	void remove_all(int val) {

		Node* curr = head;
		int index = 0;
		while (curr)
		{
			if (curr->data == val)
			{
				remove(index);
				index--;
			}
			index++;
			curr = curr->next;
		}

	}

	void group(int a, int b) {
		long sum = 0;
		if (a < 0 || a > size - 1 || b < 0 || b > size - 1)
		{
			cout << "fail_grouping";
			return;
		}

		if (b - a <= 0) return;

		Node* curr = head;

		for (int i = 0; i < a; i++)
		{
			curr = curr->next;
		}
		for (int i = a; i <= b; i++)
		{
			sum += curr->data;
			curr = curr->next;
			remove(a);
		}

		add(sum, a);
	}

	void count(int val) {

		Node* curr = head;
		int count = 0;
		while (curr != nullptr)
		{
			if (curr->data == val)
			{
				count++;
			}
			curr = curr->next;
		}

		cout << count;
	}

	int get(int index) {

		if (index > size - 1)
		{
			throw out_of_range("Index out of range!");
		}
		Node* curr = head;
		for (int i = 0; i < index; i++)
		{
			curr = curr->next;
		}
		return curr->data;
	}

	void is_palindrome() {

		int front = 0;
		int back = size - 1;

		int listSize = size % 2 == 1 ? size / 2 + 1 : size / 2;

		for (int i = 0; i < listSize; i++)
		{
			if (get(front) != get(back))
			{
				cout << "false";
				return;
			}
			front++;
			back--;
		}

		cout << "true";
	}

	~LinkedList() {
		delete head;
	}

private:
	Node* head;
	int size;
};

int main() {
	int cases;
	std::cin >> cases;
	for (int i = 0; i < cases; i++) {
		LinkedList ll;
		int ops;
		std::string op;
		std::cin >> ops;
		for (int j = 0; j < ops; j++) {
			cin >> op;

			if (op == "count") {
				int arg1;
				std::cin >> arg1;
				ll.count(arg1);
			}

			if (op == "add") {
				int arg1, arg2;
				std::cin >> arg1 >> arg2;
				ll.add(arg1, arg2);
			}

			if (op == "print") {
				ll.print();
			}

			if (op == "remove") {
				int arg1;
				std::cin >> arg1;
				ll.remove(arg1);
			}

			if (op == "reverse") {
				ll.reverse();
			}

			if (op == "remove_all") {
				int arg1;
				std::cin >> arg1;
				ll.remove_all(arg1);
			}

			if (op == "group") {
				int arg1, arg2;
				std::cin >> arg1 >> arg2;
				ll.group(arg1, arg2);
			}

			if (op == "is_palindrom") {
				ll.is_palindrome();
			}
		}

		std::cout << std::endl;

	}
	return 0;
}
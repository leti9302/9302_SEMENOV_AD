#include <iostream>
#include "List.h"

using namespace std;

List::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

List::~List() {
	clear();
}

void List::push_back(int newElem)
{
	if (size == 0) {
		head = new Node(newElem);
		tail = head;
	}
	else {
		tail->next = new Node(newElem);
		tail = tail->next;
	}
	size++;
}

void List::push_front(int newElem)
{
	if (size == 0) {
		head = new Node(newElem);
		tail = head;
	}
	else {
		head = new Node(newElem, head);
	}
	size++;
}

void List::pop_back()
{
	if (size == 0) return;

	if (size == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* current = head;
		while (current->next != tail) {
			current = current->next;
		}
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
}

void List::pop_front()
{
	if (size == 0) return;

	if (size == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* current = head->next;
		head->next = nullptr;
		delete head;
		head = current;
	}
	size--;
}

void List::insert(int newElem, size_t index)
{	
	if (index == 0) {
		push_front(newElem);
	}
	else if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	else {
		Node* current = head;
		size_t counter = 0;
		while (counter != index - 1) {
			current = current->next;
			counter++;
		}
		current->next = new Node(newElem, current->next);
		size++;
	}
}

int List::at(size_t index)
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	else {
		size_t counter = 0;
		Node* current = head;
		while (counter != index) {
			current = current->next;
			counter++;
		}
		return current->data;
	}
}

void List::remove(size_t index)
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	if (index == 0) {
		pop_front();
	}
	else if (index == size - 1) {
		pop_back();
	}
	else {
		size_t counter = 0;
		Node* current = head, * current_delete;
		while (counter != index - 1) {
			current = current->next;
			counter++;
		}
		current_delete = current->next;
		current->next = (current->next)->next;
		delete current_delete;
		size--;
	}
}

size_t List::get_size() {
	return size;
}

void List::print_to_console()
{
	size_t counter = 0;
	Node* current = head;
	while (counter != size) {
		cout << current->data << ' ';
		current = current->next;
		counter++;
	}
	cout << '\n';
}

void List::clear()
{
	while (size != 0) {
		pop_back();
	}
}

void List::set(size_t index, int newElem)
{
	if (index >= size) {
		throw out_of_range("OUT");
	}
	size_t counter = 0;
	Node* current = head;
	while (counter != index) {
		current = current->next;
		counter++;
	}
	current->data = newElem;
}

bool List::isEmpty()
{
	if (size == 0) return true;
	else return false;
}

void List::push_back(List add)
{
	if (add.get_size() > 0) {
		size_t counter = 0;
		Node* current = add.head;
		while (counter < add.get_size()) {
			push_back(current->data);
			current = current->next;
			counter++;
		}
	}
}

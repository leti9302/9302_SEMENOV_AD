#pragma once
class List //Class for the list
{
private:
	class Node	//Class for the node of the list
	{
	public:
		Node(int data, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		};
		~Node() {};

		int data;
		Node* next;
	};
	Node* head; //First element of the list
	Node* tail; //Last element of the list
	size_t size; //Size of the list
public:
	List();
	~List();

	void push_back(int); //Add a new element to the end of the list
	void push_front(int); //Add a new element to the top of the list
	void pop_back(); //Delete last element
	void pop_front(); //Delete first element
	void insert(int, size_t); //Add new element by index
	int at(size_t); //Get element by index
	void remove(size_t); //Delete element by index
	size_t get_size(); //Get the size of the list
	void print_to_console(); //Print all elements to the console
	void clear(); //Delete all elements of the list
	void set(size_t, int); //Replace element by index
	bool isEmpty(); //Check if the list is empty
	void push_back(List); //Add another list to the end of the list
};
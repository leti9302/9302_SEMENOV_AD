#include <iostream>
#include "List.h"
using namespace std;

void main() {
	List* lst = new List();
	lst->push_back(1);
	lst->push_back(2);
	lst->push_front(3);
	lst->print_to_console();
	lst->set(1, 3);
	lst->pop_back();
	lst->print_to_console();
	delete lst;
}
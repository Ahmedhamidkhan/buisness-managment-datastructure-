#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Node
{
	string order;     	// order
	Node* prev;  	// A reference to the previous Node
	Node* next; 	// A reference to the next Node
};

class Doubly_Linked_List
{
	Node* front;  	// points to first Node of list
	Node* end;   	// points to first las of list
public:
	Doubly_Linked_List()
	{
		front = NULL;
		end = NULL;
	}
	void add_front(string);
	void add_after(Node*, string);
	void add_before(Node*, string);
	void add_end(string);
	void delete_Node(Node*);
	void forward_traverse();
	void backward_traverse();
};

void Doubly_Linked_List::add_front(string d)
{
	// Creating new Node
	Node* temp;
	temp = new Node();
	temp->order = d;
	temp->prev = NULL;
	temp->next = front;

	// List is empty
	if (front == NULL)
		end = temp;

	else
		front->prev = temp;

	front = temp;
}

void Doubly_Linked_List::add_before(Node* n, string d)
{
	Node* temp;
	temp = new Node();
	temp->order = d;
	temp->next = n;
	temp->prev = n->prev;
	n->prev = temp;

	//if Node is to be inserted before first Node
	if (n->prev == NULL)
		front = temp;
}

void Doubly_Linked_List::add_after(Node* n, string d)
{
	Node* temp;
	temp = new Node();
	temp->order = d;
	temp->prev = n;
	temp->next = n->next;
	n->next = temp;

	//if Node is to be inserted after last Node
	if (n->next == NULL)
		end = temp;
}

void Doubly_Linked_List::add_end(string d)
{
	// create new Node
	Node* temp;
	temp = new Node();
	temp->order = d;
	temp->prev = end;
	temp->next = NULL;

	// if list is empty
	if (end == NULL)
		front = temp;
	else
		end->next = temp;
	end = temp;
}

void Doubly_Linked_List::delete_Node(Node* n)
{
	// if Node to be deleted is first Node of list
	if (n->prev == NULL)
	{
		front = n->next; //the next Node will be front of list
		front->prev = NULL;
	}
	// if Node to be deleted is last Node of list
	else if (n->next == NULL)
	{
		end = n->prev;   // the previous Node will be last of list
		end->next = NULL;
	}
	else
	{
		//previous Node's next will point to current Node's next
		n->prev->next = n->next;
		//next Node's prev will point to current Node's prev
		n->next->prev = n->prev;
	}
	//delete Node
	delete(n);
}

void Doubly_Linked_List::forward_traverse()
{
	Node* trav;
	trav = front;
	while (trav != NULL)
	{
		cout << trav->order << endl;
		trav = trav->next;
	}
}

void Doubly_Linked_List::backward_traverse()
{
	Node* trav;
	trav = end;
	while (trav != NULL)
	{
		cout << trav->order << endl;
		trav = trav->prev;
	}
}


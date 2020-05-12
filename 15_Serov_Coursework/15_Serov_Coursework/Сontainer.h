#pragma once
#include "Sewing_workshop.h"
#include "Furniture_workshop.h"
#include <fstream>
//Doubly Circular Linked List
struct Node
{
	Workshop* data; // workshop data
	Node* next_node;
	Node* prev_node;
};
/*
Circular Doubly Linked List has properties of both doubly linked list 
and circular linked list in which two consecutive elements are linked 
or connected by previous and next pointer and the last node points to 
first node by next pointer and also the first node points to last node 
by previous pointer.
*/
class Ñontainer
{
private:
	Node* current_node;
	Node* start_node; // main node
public:
	Ñontainer();
	~Ñontainer();

	void Push(Workshop* new_item); // standart push method adding element and makes it previous to start_node
	void Pop();
	unsigned Count_elements() const; // return counted elements

	bool Print() const; // print all elements on screen
	bool Delete_element(string title_to_delete); // pop element by title
	bool Save() const; // save all elements to file
	void Load(); // load all elements from file
	bool Sort_elements_by_title();
	bool Count_capacity() const; // avarage capacity * workbanches in workshops
	bool Delete_all();
};
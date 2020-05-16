#include "Workshop.h"

Workshop::Workshop() : workshop_title("Noname"), num_of_workbench(0), average_capacity(0)
{}

Workshop::Workshop(string title, unsigned short workbench, int capacity) :
	workshop_title(title), num_of_workbench(workbench), average_capacity(capacity)
{}

Workshop::~Workshop()
{}

string Workshop::Get_title() const
{
	return workshop_title;
}

unsigned short Workshop::Get_workbench() const
{ 
	return num_of_workbench; 
}

int Workshop::Get_capacity() const
{
	return average_capacity;
}

void Workshop::Set_title(string new_title)
{
	workshop_title = new_title;
}

void Workshop::Set_workbench(unsigned short new_workbench)
{
	num_of_workbench = new_workbench;
}

void Workshop::Set_capacity(int new_capacity)
{
	average_capacity = new_capacity;
}

void Workshop::Print_workshop()
{
	cout << "\nTitle: " << Workshop::Get_title() 
		<< "\nWorkbenches: " << Workshop::Get_workbench()
		<< "\nCapacity: " << Workshop::Get_capacity() << endl;
}
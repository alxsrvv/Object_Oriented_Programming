//#define _CRT_SECURE_NO_WARNINGS
#include "Workshop.h"
#include <string>
#include <iostream>
using namespace std;

Workshop::Workshop() : workshop_title("Noname"), num_of_workbench(0), average_capacity(0)
{}
Workshop::Workshop(string title, unsigned short workbench, float capacity) :
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
float Workshop::Get_capacity() const
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
void Workshop::Set_capacity(float new_capacity)
{
	average_capacity = new_capacity;
}
void Workshop::Print_workshop()
{
	cout << '\n' << Workshop::Get_title() << '\n'
		<< Workshop::Get_workbench() << '\n'
		<< Workshop::Get_capacity() << endl;
}
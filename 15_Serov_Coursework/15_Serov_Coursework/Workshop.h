#pragma once
#include <string>
#include <iostream>
using namespace std;
/*
	Base class with basic workshop info
*/
class Workshop
{
protected:
	string workshop_title;
	unsigned short num_of_workbench;
	int average_capacity;
public:
	Workshop();
	Workshop(string title, unsigned short workbench, int capacity);
	virtual ~Workshop();

	string Get_title() const;
	unsigned short Get_workbench() const;
	int Get_capacity() const;

	void Set_title(string new_title);
	void Set_workbench(unsigned short new_workbench);
	void Set_capacity(int new_capacity);

	virtual void Print_workshop() = 0;
};
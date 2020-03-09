#pragma once
//#define _CRT_SECURE_NO_WARNINGS
#include <string>
using namespace std;

class Workshop
{
protected:
	string workshop_title;
	unsigned short num_of_workbench;
	float average_capacity;
public:
	Workshop();
	Workshop(string title, unsigned short workbench, float capacity);
	virtual ~Workshop();

	string Get_title() const;
	unsigned short Get_workbench() const;
	float Get_capacity() const;

	void Set_title(string new_title);
	void Set_workbench(unsigned short new_workbench);
	void Set_capacity(float new_capacity);

	void Print_workshop();
};
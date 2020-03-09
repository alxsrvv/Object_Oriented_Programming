#pragma once
#include "Workshop.h"
#include <string>
using namespace std;

class Furniture_workshop : public Workshop
{
private:
	string wood_type;
	unsigned amount_of_wood;
public:
	Furniture_workshop();
	Furniture_workshop(string title, unsigned short workbench, float capacity, string wood, unsigned amount);
	virtual ~Furniture_workshop();

	string Get_wood() const;
	unsigned Get_amount() const;

	void Set_wood(string new_wood);
	void Set_amount(unsigned new_amount);

	void Print_furniture_workshop();
};
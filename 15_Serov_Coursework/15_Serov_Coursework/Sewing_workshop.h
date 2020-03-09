#pragma once
#include "Workshop.h"
#include <string>
using namespace std;

class Sewing_workshop : public Workshop
{
private:
	string fabric_type;
	unsigned rolls_of_fabric;
public:
	Sewing_workshop();
	Sewing_workshop(string title, unsigned short workbench, float capacity, string fabric, unsigned rolls);
	virtual ~Sewing_workshop();

	string Get_fabric() const;
	unsigned Get_rolls() const;

	void Set_fabric(string new_fabric);
	void Set_rolls(unsigned new_rolls);

	void Print_sewing_workshop();
};
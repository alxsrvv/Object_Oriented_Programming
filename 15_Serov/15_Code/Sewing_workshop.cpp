#include "Sewing_workshop.h"

Sewing_workshop::Sewing_workshop() : fabric_type("None"), rolls_of_fabric(0)
{}

Sewing_workshop::Sewing_workshop(string title, unsigned short workbench, int capacity, string fabric, unsigned rolls) :
	Workshop(title, workbench, capacity), fabric_type(fabric), rolls_of_fabric(rolls)
{}

Sewing_workshop::~Sewing_workshop()
{}

string Sewing_workshop::Get_fabric() const
{
	return fabric_type;
}

unsigned Sewing_workshop::Get_rolls() const
{
	return rolls_of_fabric;
}

void Sewing_workshop::Set_fabric(string new_fabric)
{
	fabric_type = new_fabric;
}

void Sewing_workshop::Set_rolls(unsigned new_rolls)
{
	rolls_of_fabric = new_rolls;
}

istream& operator >> (istream& is, Sewing_workshop& sew_is)
{
	is >> sew_is.workshop_title >> sew_is.num_of_workbench >> sew_is.average_capacity >> 
		sew_is.fabric_type >> sew_is.rolls_of_fabric;
	return is;
}

ostream& operator << (ostream& os, Sewing_workshop& sew_os)
{
	os << sew_os.workshop_title << '\n' << sew_os.num_of_workbench << '\n' << sew_os.average_capacity << 
		'\n' << sew_os.fabric_type << '\n' << sew_os.rolls_of_fabric << '\n';
	return os;
}

void Sewing_workshop::Print_workshop()
{
	Workshop::Print_workshop();
	cout << "Fabric type: " << Sewing_workshop::Get_fabric() 
		<< "\nRolls: " << Sewing_workshop::Get_rolls() << '\n' << endl;
}
#include "Furniture_workshop.h"

Furniture_workshop::Furniture_workshop() : wood_type("None"), amount_of_wood(0)
{}

Furniture_workshop::Furniture_workshop(string title, unsigned short workbench, int capacity, string wood, unsigned amount) :
	Workshop(title, workbench, capacity), wood_type(wood), amount_of_wood(amount)
{}

Furniture_workshop::~Furniture_workshop()
{}

string Furniture_workshop::Get_wood() const
{
	return wood_type;
}

unsigned Furniture_workshop::Get_amount() const
{
	return amount_of_wood;
}

void Furniture_workshop::Set_wood(string new_wood)
{
	wood_type = new_wood;
}

void Furniture_workshop::Set_amount(unsigned new_amount)
{
	amount_of_wood = new_amount;
}

istream& operator >> (istream& is, Furniture_workshop& fur_is)
{
	is >> fur_is.workshop_title >> fur_is.num_of_workbench >> fur_is.average_capacity >>
		fur_is.wood_type >> fur_is.amount_of_wood;
	return is;
}

ostream& operator << (ostream& os, Furniture_workshop& fur_os)
{
	os << fur_os.workshop_title << '\n' << fur_os.num_of_workbench << '\n' << fur_os.average_capacity <<
		'\n' << fur_os.wood_type << '\n' << fur_os.amount_of_wood << endl;
	return os;
}

void Furniture_workshop::Print_workshop()
{
	Workshop::Print_workshop();
	cout << "Wood type: " << Furniture_workshop::Get_wood()
		<< "\nAmount: " << Furniture_workshop::Get_amount() << '\n' << endl;
}
#include "Appartment_array.h"
#include <iostream>
using namespace std;

Appartment_array::Appartment_array(const Appartment_struct* class_array, unsigned short new_length) :
	m_length(new_length)
{
	this->m_class_array = new Appartment * [m_length];
	for (short i = 0; i < m_length; i++)
	{
		this->m_class_array[i] = new Appartment(
			class_array[i]._address,
			class_array[i]._floor,
			class_array[i]._rooms,
			class_array[i]._area);
	}
}

Appartment_array::~Appartment_array()
{
	for (short i = 0; i < m_length; i++)
		delete m_class_array[i];
	delete[] m_class_array;
}

void Appartment_array::floor_gap(short start, short stop) const
{
	cout << "Appartments between " << start << " and " << stop << " floor :\n";
	for (short i = 0; i < m_length; i++)
	{
		if (m_class_array[i]->GetFloor() >= start && m_class_array[i]->GetFloor() <= stop)
			cout << "\t" << m_class_array[i]->GetAddress() << " is on " << m_class_array[i]->GetFloor() << " floor\n";
	}
	cout << "\n\n";
}

void Appartment_array::rooms_appartment(unsigned short rooms) const
{
	cout << "Appartments, that has " << rooms << " rooms :\n";
	for (short i = 0; i < m_length; i++)
	{
		if (m_class_array[i]->GetRooms() == rooms)
			cout << "\t" << m_class_array[i]->GetAddress() << endl;
	}
	cout << "\n\n";
}

void Appartment_array::larger_than(unsigned area) const
{
	cout << "Appartments, that has an area bigger than " << area << " :\n";
	for (short i = 0; i < m_length; i++)
	{
		if (m_class_array[i]->GetArea() > area)
			cout << "\t" << m_class_array[i]->GetAddress() << " has area " << m_class_array[i]->GetArea() << endl;
	}
	cout << "\n\n";
}
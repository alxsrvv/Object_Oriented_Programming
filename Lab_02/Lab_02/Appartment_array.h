#pragma once
#include "Appartment.h"
struct Appartment_struct
{
	char* _address;
	short _floor;
	unsigned short _rooms;
	unsigned int _area;
};

class Appartment_array
{
	Appartment** m_class_array;
	unsigned m_length;
public:
	Appartment_array(const Appartment_struct *class_array, unsigned short new_length);
	~Appartment_array();

	void floor_gap(short start, short stop) const;
	void rooms_appartment(unsigned short rooms) const;
	void larger_than(unsigned area) const;
};
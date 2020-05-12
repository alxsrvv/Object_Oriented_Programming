#pragma once
class Appartment
{
	char* m_address;
	short m_floor;
	unsigned short m_rooms;
	unsigned int m_area;

public:
	Appartment();
	Appartment(const char* address, short floor, unsigned short rooms, unsigned area);
	~Appartment();

	const char* GetAddress() const { return m_address; }
	short GetFloor() const { return m_floor; }
	unsigned short GetRooms() const { return m_rooms; }
	unsigned GetArea() const { return m_area; }

	void SetAddress(const char* address);
	void SetFloor(short floor);
	void SetRooms(unsigned short rooms);
	void SetArea(unsigned area);

	void Print();
};
#pragma once
class Building
{
protected:
	char* m_address;
	unsigned m_area;
	char* m_use;
public:
	Building(const char* adrs = "st. noname 0", unsigned area = 0, const char* use = "Any use");
	~Building();

	const char* Get_address();
	unsigned Get_area();
	const char* Get_use();

	void Set_address(const char* adrs);
	void Set_area(unsigned area);
	void Set_use(const char* use);

	virtual void Print();
};
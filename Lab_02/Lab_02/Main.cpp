#include "Appartment.h"
#include "Appartment_array.h"
#include <iostream>
using namespace std;

void main()
{
	cout << "This program can show information about different appartments.\n\n";

	char address_1[] = "st. Waileys 25 / 5";
	char address_2[] = "st. Greens 54 / 33";
	char address_3[] = "st. Droobs 234 / 2b";
	char address_4[] = "alley Blows 67 / 1";
	char address_5[] = "st. Ullows 77 / 3";
	Appartment_struct class_array[5] =
	{
	   //adrs, flr, rms, area
		{address_1, 5, 5, 1256},
		{address_2, 6, 7, 1800},
		{address_3, 3, 3, 954},
		{address_4, 1, 6, 1553},
		{address_5, -1, 5, 1192}
	};

	Appartment_array arr(class_array, 5);

	arr.floor_gap(1, 4);
	arr.rooms_appartment(5);
	arr.larger_than(1000);

	system("pause");
}
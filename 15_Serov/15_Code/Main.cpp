#include "Menu.h"
/*
	This program add/edit/find/sort/save/load/delete workshops info.
		by Alexander Serov
*/
void main()
{
	Menu* Workshop_data_manage = Menu::GetInstance(); // singleton menu creation
	Workshop_data_manage->Start(); // start of main menu
	system("pause");
}

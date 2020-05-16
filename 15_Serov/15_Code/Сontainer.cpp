#include "Ñontainer.h"

Ñontainer::Ñontainer() : current_node(NULL)
{}

Ñontainer::~Ñontainer()
{ 
	Delete_all(); 
}

void Ñontainer::Push(Workshop* new_item)
{
	Node* new_node = new Node;
	new_node->data = new_item; //make a node with parameter data

	if (current_node) // if container have at least 1 element - link them
	{
		new_node->next_node = current_node;
		current_node->prev_node = new_node;
	}
	else
		start_node = new_node;
	// connecting first and last nodes
	new_node->prev_node = start_node;
	start_node->next_node = new_node;
	current_node = new_node;
}

void Ñontainer::Pop()
{
	Node* tmp_node = start_node;

	if (tmp_node->next_node == tmp_node) // if element point to itself - delete single element
		start_node = NULL;
	else
	{
		if (tmp_node == start_node)
			start_node = start_node->next_node; // if pop main element - make next element new main
		// connection exchange between nodes near popped element
		(tmp_node->next_node)->prev_node = tmp_node->prev_node;
		(tmp_node->prev_node)->next_node = tmp_node->next_node;
	}
}

unsigned Ñontainer::Count_elements() const
{
	if (start_node)
	{
		unsigned num_of_elements = 0;
		Node* tmp_node = start_node;

		do
		{
			tmp_node = tmp_node->prev_node;
			num_of_elements++;
		}
		while (tmp_node != start_node);
		return num_of_elements;
	}
	else
	{
		cout << "\nContainer clear. There are no workshops!\n";
		return 0;
	}
}

bool Ñontainer::Print() const
{
	bool print_flag = false; // flag show success of printing
	Node* tmp_node = start_node;

	if (start_node)
	{
		cout << "\n|--------------------------------------|\n"
			<< ">--------------   DATA   --------------<\n"
			<< "|--------------------------------------|\n";
		do
		{
			tmp_node->data->Print_workshop();
			tmp_node = tmp_node->next_node;
		} while (tmp_node != start_node);
		cout << "|--------------------------------------|\n\n";
		print_flag = true;
	}
	return print_flag;
}

bool Ñontainer::Delete_element(string title_to_delete)
{
	bool pop_flag = false;  // flag show success of finding and deleting the node
	Node* tmp_node = start_node;
	
	do // cicle working before it find needed title or make a loop in container
	{
		if (tmp_node->data->Get_title() == title_to_delete)
		{
			pop_flag = true;
			Pop();
			break;
		}
		tmp_node = tmp_node->next_node;
	}
	while (tmp_node != start_node);
	return pop_flag;
}

bool Ñontainer::Save() const
{
	bool save_flag = false; // flag show that container have at least one element

	if (start_node)
	{
		save_flag = true;
		ofstream save_file;
		save_file.open("Workshops_info.txt"); // make or remake file

		if (save_file.is_open())
		{
			Node* tmp_node = start_node;
			unsigned containers_length = Count_elements();

			for (unsigned i = 0; i < containers_length; i++)
			{
				if (typeid(*(tmp_node->data)) == typeid(Sewing_workshop))
				{
					save_file << 1 << '\n'; // for easier data processing added label to sewing workshops...
					save_file << *((Sewing_workshop*)(tmp_node->data)); // print method declarated in Sewing_workshop.h
				}
				if (typeid(*(tmp_node->data)) == typeid(Furniture_workshop))
				{
					save_file << 2 << '\n'; // and furniture workshops
					save_file << *((Furniture_workshop*)(tmp_node->data)); // print method declarated in Furniture_workshop.h
				}
				tmp_node = tmp_node->next_node;
			}
			save_file.close();
			cout << "\nData saved in 'Workshops_info.txt'\n\n";
		}
		else
			cout << "\nError: data may not saved properly!\n\n";
	}
	return save_flag;
}

void Ñontainer::Load()
{
	ifstream read_file;
	read_file.open("Workshops_info.txt"); // open file

	if (read_file.is_open())
	{
		char one_two_string[2]; // char that will read labels of workshops
		read_file.getline(one_two_string, 2); // reading first label
		unsigned char one_two_num = atoi(one_two_string); // transform char to number

		Sewing_workshop* sewing_1; // temp workshops
		Furniture_workshop* furniture_2;

		while (!read_file.eof()) // while file not end yet
		{
			if (one_two_num == 1)
			{
				sewing_1 = new Sewing_workshop();
				read_file >> (*sewing_1); // read method declarated in Sewing_workshop.h
				Push(sewing_1); // add workshop to container
			}
			else if (one_two_num == 2)
			{
				furniture_2 = new Furniture_workshop();
				read_file >> (*furniture_2);// read method declarated in Furniture_workshop.h
				Push(furniture_2); // add workshop to container
			}
			read_file.getline(one_two_string, 2); // reading next workshop label
			one_two_num = atoi(one_two_string); // and transform char to number
		}
		read_file.close();
	}
	else
		cout << "\nError: poor data!\n\n";
}
/*
	Sort_elements_by_title() will sort nodes of the list in ascending order.

	1. Define a node current which will point to head.
	2. Define another node index which will point to node next to current.
	3. Compare data of current and index node. If the current's data is greater than the index's data, then swap the data between them.
	4. Current will point to current->next_node and index will point to index->next_node.
	5. Continue this process till the entire list is sorted.
*/
bool Ñontainer::Sort_elements_by_title()
{
	bool sort_flag = false; // flag show that container have at least one element

	if (start_node)
	{
		sort_flag = true;
		unsigned containers_length = Count_elements() - 1; // length of container without 1 used temporary node
		Node* current = start_node;
		Node* index;
		Workshop* tmp; // temp workshop

		for (int i = 0; i < containers_length; i++)
		{
			index = current->next_node;
			for (int j = 0; j < containers_length; j++)
			{
				if (current->data->Get_title() < index->data->Get_title())
				{
					tmp = index->data;
					index->data = current->data;
					current->data = tmp;
				}
				index = index->next_node;
			}
			current = current->next_node;
		}
		start_node = current;
	}
	return sort_flag;
}

bool Ñontainer::Count_capacity() const
{
	if (start_node)
	{
		cout << "\nThis function can find capacity of all workshops by type.\nEnter type:\n\n>";
		string type_to_count = "";
		cin >> type_to_count;

		bool type_flag = false; // flag show success of founding type
		float full_capacity = 0;
		Node* tmp_node = start_node;

		do
		{
			if (typeid(*(tmp_node->data)) == typeid(Sewing_workshop)) // type is Sewing_workshop.. 
			{
				if ( (((Sewing_workshop*)(tmp_node->data))->Get_fabric()) == type_to_count ) // and titles match up
				{
					full_capacity += (tmp_node->data->Get_capacity()) * (tmp_node->data->Get_workbench());
					type_flag = true; // adding multiply of benches and average capacity and flag turn up
				}
			}	
			else if (typeid(*(tmp_node->data)) == typeid(Furniture_workshop)) // type is Furniture_workshop.. 
			{
				if ( (((Furniture_workshop*)(tmp_node->data))->Get_wood()) == type_to_count )  // and titles match up
				{
					full_capacity += tmp_node->data->Get_capacity() * tmp_node->data->Get_workbench();
					type_flag = true; // adding multiply of benches and average capacity and flag turn up
				}
			}
			tmp_node = tmp_node->next_node;
		}
		while (tmp_node != start_node);
		if (type_flag)
			cout << "\nFull capacity of all " << type_to_count << " workshops: " << full_capacity << "\n\n";
		else
			cout << "\nError: Type not found!\n\n";
		return true; // there is at least one node and finding end with success
	}
	return false; // there is no nodes in container
}

bool Ñontainer::Delete_all()
{
	if (start_node)
	{
		while (start_node) // end - start_node is NULL
		{
			Pop();
		}
		current_node = NULL;
		return true;
	}
	return false;
}
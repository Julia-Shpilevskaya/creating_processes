#include <conio.h>
#include <iostream>
#include <fstream>
#include<string>
#include "Employee.h"


int main(int argc, char* argv[])
{
	std::string file_name = argv[1];
	int number_of_employees = std::stoi(argv[2]);
	std::ofstream fout;
	fout.open(file_name,std::ios::binary);
	employee people;

	if (fout.is_open())
	{
		std::cout << "Enter the employee ID number, name and number of hours worked\n";

		for (int i = 1;i <= number_of_employees; i ++)
		{
			std::cout << i << ".";
			std::cin >> people.num >> people.name >> people.hours;
			fout.write((char*)&people, sizeof(employee));
		}
	}

	fout.close();

	return 0;
}
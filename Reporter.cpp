#include <conio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Employee.h"


int main(int argc, char* argv[])
{
	std::string bin_file_name = argv[1];
	std::string output_file_name = argv[2];
	double payment_per_hour_of_work = std::stoi(argv[3]);
	std::ifstream fin;
	fin.open(bin_file_name, std::ios::binary);
	std::vector<employee> people;
	employee employe;

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.read((char*)&employe, sizeof(employee));
			people.push_back(employe);
		}
		people.pop_back();
	}

	fin.close();

	std::ofstream fout;
	fout.open(output_file_name);

	if (fout.is_open())
	{
		fout << "File report \"" << bin_file_name << "\"\n";
		fout << "ID\t name\t number of hours worked\t payment per hour of work\n";

		for (int i = 0; i < people.size();i++) {
			fout << people[i].num << "\t" << people[i].name << "\t" << people[i].hours << "\t\t\t" << people[i].hours * payment_per_hour_of_work << "\n";
		}
	}

	fout.close();

	return 0;
}
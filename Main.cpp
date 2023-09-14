#include <windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include"Employee.h"


int main()
{
	std::string bin_file_name;
	std::cout << "Enter binary file name\n";
	std::cin >> bin_file_name;

	std::string number_of_employees;
	std::cout << "Enter number of employees\n";
	std::cin >> number_of_employees;

	std::string creator = "Creator.exe " + bin_file_name + " " + number_of_employees;
	std::wstring transformed_creator = std::wstring(creator.begin(), creator.end());
	LPWSTR lpszAppName = &transformed_creator[0];

	STARTUPINFO si;
	PROCESS_INFORMATION piApp;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);

	if (!CreateProcess(NULL, lpszAppName, NULL, NULL, FALSE,
		CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp))
	{
		std::cout << "error";
		return 0;
	}

	WaitForSingleObject(piApp.hProcess, INFINITE);

	std::vector<employee> people;
	std::ifstream fin;
	employee employe;
	fin.open(bin_file_name, std::ios::binary);

	if (fin.is_open())
	{
		std::cout << "ID\t name\t number of hours worked\n";

		while (!fin.eof())
		{
			fin.read((char*)&employe, sizeof(employee));
			people.push_back(employe);
		}
		people.pop_back();

		for(int i = 0;i < people.size(); i++)
			std::cout << people[i].num << "\t" << people[i].name << "\t" << people[i].hours << "\n";
	}

	std::string output_file_name;
	std::cout << "Enter output file name (.txt)\n";
	std::cin >> output_file_name;

	std::string payment_per_hour_of_work;
	std::cout << "Enter payment per hour of work\n";
	std::cin >> payment_per_hour_of_work;

	std::string reporter = "Reporter.exe " + bin_file_name + " " + output_file_name + " " + payment_per_hour_of_work;
	std::wstring transformed_reporter = std::wstring(reporter.begin(), reporter.end());
	lpszAppName = &transformed_reporter[0];

	STARTUPINFO si2;
	PROCESS_INFORMATION piApp2;
	ZeroMemory(&si2, sizeof(STARTUPINFO));
	si2.cb = sizeof(STARTUPINFO);

	if (!CreateProcess(NULL, lpszAppName, NULL, NULL, FALSE,
		CREATE_NEW_CONSOLE, NULL, NULL, &si2, &piApp2))
	{
		std::cout << "error";
		return 0;
	}

	WaitForSingleObject(piApp2.hProcess, INFINITE);

	std::ifstream fin2;
	fin2.open(output_file_name);
	std::vector<double> salary;
	std::string file_text;

	if (fin2.is_open())
	{
		while (!fin2.eof())
		{
			getline(fin2, file_text);
			std::cout << file_text << "\n";
		}
	}

	fin2.close();
	_getch();
	CloseHandle(piApp.hThread);
	CloseHandle(piApp.hProcess);

	return 0;
}
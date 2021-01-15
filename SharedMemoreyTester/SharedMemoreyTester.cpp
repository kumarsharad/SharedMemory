// SharedMemoreyTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../SharedMemoryLibrary/SharedMemoryLibraray.h"
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int EXIT = -1;
	char str[64] = { '\0' };
	std::cout << "Options : 0 - Exit, 1 - Get String, 2 - Add String, 3 - Delete String\n";
	while (EXIT != 0)
	{
		std::cout << "\nChoice : ";
		scanf_s("%d", &EXIT); std::cout << "\t\t";
		switch (EXIT)
		{
		case 0:
			EXIT = 0; break;
		case 1:
			if(GetString(str))
				std::cout << "String is : " << str << "\n";
			else
				std::cout << "String not found\n";
			break;
		case 2:
			DeleteString();
			std::cout << "Enter string to store : ";
			scanf_s("%s", str, 64);
			if(AddString(str))
				std::cout << "\t\tString stored\n";
			else
				std::cout << "\t\tString not stored\n";
			break;
		case 3:
			if(DeleteString())
			 std::cout << "String deleted\n ";
			else
				std::cout << "String not found to delete\n ";
			break;
		default:
			EXIT = TRUE;
			break;
		}
	}
}
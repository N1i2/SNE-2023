#include "stdafx.h"
#include "mylib.h"
#include <iostream>
#include <Windows.h>
#pragma warning(disable: 4996)


extern "C"
{
	int _stdcall texttolit(char* str1)
	{
		int result = 0;

		for (int i = 0; str1[i] != '\0'; ++i)
			result = result * 10 + str1[i] - '0';

		return result;
	}

	int _stdcall textlenght(char* str1) {
		int i=0;
		while (*(str1 + i) != NULL)
		{
			
			i++;
		}
		return i;
	}

	char* _stdcall copytxt(char* str1, char* str2)
	{
		return strcpy(str1, str2);
	}

	int _stdcall sleep() {
		system("pause");
		return 1;
	}

	int __stdcall outtxt(char* value)
	{
		std::cout << value << std::endl;
		return 1;
	}

	int __stdcall outlit(int value)
	{
		std::cout << value << std::endl;
		return 1;
	}
}
#pragma once

extern "C"
{
	char* _stdcall copytxt(char* str1, char* str2);
	int _stdcall texttolit(char* str1);
	int _stdcall textlenght(char* str1);
	int _stdcall sleep();
	int __stdcall outtxt(char* value);
	int __stdcall outlit(int value);
}
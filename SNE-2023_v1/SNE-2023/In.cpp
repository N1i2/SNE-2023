#include "pch.h"
#include "In.h"
#include "Error.h"
#include "FST.h"
#include "LT.h"
#include "IT.h"
#include "LexAnaliz.h"
#include <fstream>
#include <string>
#include <iostream>


namespace In
{
	static helpInfo help;

	helpInfo getInfo()
	{
		return help;
	}

	IN getin(wchar_t infile[], wchar_t outfile[])
	{
		std::string onestr;
		int currentCol = 0;
		IN Info
		{
			0,
			0,
			0,
			nullptr,
			IN_CODE_TABLE
		};

		std::ifstream test(infile);

		test.seekg(0, std::ios::end);
		std::streampos fileSize = test.tellg();

		test.close();

		int size = static_cast<int>(fileSize);
		if(size<=15)
			throw ERROR_THROW(105);

		std::ifstream in(infile);
		std::ofstream out(outfile);

		if (!out.is_open())
			throw ERROR_THROW(101);
		if (!in.is_open())
			throw ERROR_THROW(101);

		std::string temp;
		while (!in.eof())
		{
			Info.lines++;
			std::getline(in, temp);
			temp += "\n";
			help.fulltext += temp;
		}

		help.fulltext += ' ';
		Info.text = new unsigned char[help.fulltext.size() + 1];
		unsigned char* Ptemp = Info.text;

		for (int i = 0; i < help.fulltext.size(); ++i)
		{
			if (Info.code[(unsigned char)help.fulltext[i]] == IN::F)
				throw ERROR_THROW_IN(102, help.currentLine, currentCol)
			else if (Info.code[(unsigned char)help.fulltext[i]] == IN::I)
				++Info.ignor;
			else if (Info.code[(unsigned char)help.fulltext[i]] != IN::T)
			{
				*Ptemp = help.fulltext[i];
				++Ptemp;
			}
			else
			{
				*Ptemp = Info.code[(unsigned char)help.fulltext[i]];
				++Ptemp;
			}
			if (help.fulltext[i] == '\n')
			{
				help.currentLine++;
				currentCol = 0;
			}
			else
				currentCol++;
		}
		*Ptemp = IN_CODE_ENDL;
		Info.size = help.fulltext.size() - Info.lines;

		out << Info.text;
		return Info;
	}
}
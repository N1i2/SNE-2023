#include"stdafx.h"

namespace LT
{
	LexTable Create(int size)
	{
		if (size > LT_MAXSIZE) 
			throw ERROR_THROW(110);

		LexTable Table;
		Table.maxSize = size;
		Table.size = 0;
		Table.table = new Entry[size];

		return Table;
	}

	void Add(LexTable& lextable, Entry entry)
	{
		if (lextable.size > lextable.maxSize)
			throw ERROR_THROW(111);

		lextable.table[lextable.size++] = entry;
	}

	Entry GetEntry(LexTable& lextable, int n)
	{
		return lextable.table[n];
	}

	void Delete(LexTable& lextable)
	{
		delete[] lextable.table;
	}
	void showLT(LexTable& lextable, std::ofstream &file)
	{
		file << std::setfill('=') << std::setw(25) << "LEX TABLE" << std::setw(16) << "\n\n";
		file << "Num" << std::setfill(' ') << std::setw(10) << "Line" << std::setw(9) << "Lexema" << std::setw(20) << "ID in IT" << std::setw(18) << "value" << "\n\n";
		for (int i = 0; i < lextable.size; i++)
		{
			file << std::setw(3) << i << std::setfill(' ') << std::setw(8) << lextable.table[i].strNumb + 1 <<
				std::setw(8) << lextable.table[i].lexema << std::setw(20);
			if (lextable.table[i].indxTI != LT_IT_NULLIDX)
				file << lextable.table[i].indxTI;
			else
				file << ' ';
			file << std::setw(20) << lextable.table[i].value << std::setw(20);
			file << std::endl;
		}
	}
}
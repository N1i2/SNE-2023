#include"stdafx.h"
#include<string.h>
#include<mbstring.h>

namespace IT
{
	IdTable Create(int size)
	{
		IdTable* newIdTable = new IdTable;

		if (size > TI_MAXSIZE)
			throw ERROR_THROW(203);

		newIdTable->maxSize = size;
		newIdTable->size = 0;
		newIdTable->table = new Entry[size];

		return *newIdTable;
	}
	void Add(IdTable& idtable, Entry entry)
	{
		if (idtable.size + 1 > idtable.maxSize)
			throw ERROR_THROW(204);

		idtable.table[idtable.size++] = entry;
	}
	Entry GetEntry(IdTable& idtable, int n)
	{
		return idtable.table[n];
	}
	int IsID(IdTable& idtable, unsigned char id[ID_MAXSIZE])
	{
		for (int i = 0; i < idtable.size; i++)
			if (_mbscmp(idtable.table[i].id, id) == 0)
				return i;

		return TI_NULLIDX;
	}
	void Delete(IdTable& idtable)
	{
		delete[] idtable.table;
	}
	void showTable(IdTable& idtable, std::ofstream& file)
	{
		int iddatatype;
		int idtype;
		int counter = 0;

		file << std::setfill('=') << std::setw(25) << "ID TABLE" << std::setw(16) << "\n\n";
		file << std::setfill(' ') << std::setw(10) << "Name" << std::setw(15) << "Type" << std::setw(18) << "Data type" <<
			std::setw(19) << "First in LT" << std::setw(21) << "Value" << std::setw(19) << "Visibility" << "\n\n";

		for (int i = 0; i < idtable.size; i++)
		{
			iddatatype = idtable.table[i].idDataType;
			idtype = idtable.table[i].idType;
			file << std::setfill(' ') << std::setw(3) << i;
			file << std::setfill(' ') << std::setw(10) << idtable.table[i].id << std::setw(15);

			switch (idtype)
			{
			case 1:
				file << std::setfill(' ') << "variable" << std::setw(15);
				break;
			case 2:
				file << std::setfill(' ') << "function" << std::setw(15);
				break;
			case 3:
				file << std::setfill(' ') << "parameter" << std::setw(15);
				break;
			case 4:
				file << std::setfill(' ') << "literal" << std::setw(15);
				break;
			case 0:
				file << std::setfill(' ') << "error" << std::setw(15);
				break;

			}

			switch (iddatatype)
			{
			case 1:
				file << std::setfill(' ') << "little" << std::setw(15);
				break;
			case 2:
				file << std::setfill(' ') << "text" << std::setw(15);
				break;
			case 3:
				file << std::setfill(' ') << "short" << std::setw(15);
				break;
			case 0:
				file << std::setfill(' ') << "error" << std::setw(15);
				break;
			}

			file << std::setfill(' ') << idtable.table[i].idxFirst << std::setw(25);


			if (idtype != 4)
				switch (iddatatype)
				{
				case 1:
					file << '0';
					break;
				case 3:
					file << '0';
					break;
				case 2:
					file << "NV";
					break;
				default:
					break;
				}
			else {
				if (iddatatype == 1)
					file << idtable.table[i].value.vshrt;
				else
					file << idtable.table[i].value.vstr.str;
			}

			counter = 1;
			file << std::setfill(' ') << std::setw(15) << '0';
			while (idtable.table[i].areaOfVisibility[counter] != NULL)
			{
				file << " " << idtable.table[i].areaOfVisibility[counter];
				counter++;
			}

			file << std::endl;
		}
	}
}
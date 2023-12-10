#pragma once
#define ID_MAXSIZE		32
#define TI_MAXSIZE		4096
#define TI_INT_DEFAULT	0x00000000
#define TI_STR_DEFAULT	0x00
#define TI_NULLIDX		0xffffffff
#define TI_STR_MAXSIZE	255

namespace IT
{
	enum IDDATATYPE { VOID = 0, SHORT = 1, STR = 2};
	enum IDTYPE { V = 1024, F = 2048, P = 2049, L = 2050, OP = 5000 };

	struct Entry
	{
		int idxFirst;
		unsigned char id[ID_MAXSIZE];
		short areaOfVisibility[5] = { 0 };

		IDDATATYPE idDataType; 
		IDTYPE idType;

		union
		{
			short vshrt;
			struct
			{
				int length;
				char str[TI_STR_MAXSIZE - 1];
			}vstr;

		}value;
	};

	struct IdTable
	{
		int maxSize;
		int size;
		Entry* table;
	};

	IdTable Create(int size);
	void Add(IdTable& idtable, Entry entry);
	Entry GetEntry(IdTable& idtable, int n);
	int IsID(IdTable& idtable,unsigned char id[ID_MAXSIZE]);
	void Delete(IdTable& idtable);
	void showTable(IdTable& idtable, std::ofstream& file);
};
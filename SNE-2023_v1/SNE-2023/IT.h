#pragma once
#define ID_MAXSIZE		32		
#define TI_MAXSIZE		4096	
#define TI_INT_DEFAULT	0x00000000	
#define TI_STR_DEFAULT	0x00		
#define TI_NULLIDX		0xffffffff	
#define TI_STR_MAXSIZE	255			

namespace IT
{
	enum IDDATATYPE { LIT = 1, TXT = 2, Err = 0 };
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, E = 0 };

	struct Entry
	{
		short areaOfVisibility[5] = { 0 };
		int	idxfirstLE;
		unsigned char id[ID_MAXSIZE];
		IDDATATYPE	iddatatype;
		IDTYPE		idtype;
		union
		{
			short vshr;
			struct
			{
				int len;
				unsigned char str[TI_STR_MAXSIZE - 1];
			} vstr;
		} value;
	};

	struct IdTable
	{
		int maxsize;
		int size;
		Entry* table;
	};

	IdTable Create(int size);

	void Add(IdTable& idtable, Entry entry);

	Entry GetEntry(IdTable& idtable, int n);

	int IsId(IdTable& idtable, unsigned char id[ID_MAXSIZE]);

	int IsIdWithAreaOfVisibility(IdTable& idtable, unsigned char id[ID_MAXSIZE], short area[5]);

	void Delete(IdTable& idtable);
	void showTable(IdTable& idtable, std::ofstream& file);
};